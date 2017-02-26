/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  actor_states.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-07
  @ description:  actor states.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_ACTOR_STATES_H_
#define CITY_HUNTER_SRC_ACTOR_STATES_H_

#include <vector>

#include "action_command.h"
#include "attack_command.h"
#include "command_constants.h"
#include "command_manager.h"
#include "game_object.h"
#include "graph_typedef.h"
#include "path_finder.h"
#include "state.h"
#include "state_constants.h"
#include "state_machine.h"
#include "scene_manager.h"
#include "space_partition.h"
#include "util/utils_graph.h"

namespace gamer
{
    
template<typename Actor>
class IdleState : public State<Actor>
{
public:
    IdleState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if(nullptr == actor)
            return;

        ActionCommand<Actor> cmd(CommandIDs::CMD_ID_PLAY_ACTION);
        cmd.set_sub_command_id(CommandIDs::CMD_ID_PLAY_IDLE_ACTION);
        cmd.set_initiator(actor);
        CommandManager::getInstance()->sendCmd(&cmd);
    }

    virtual void onUpdate(Actor* actor) override
    {
        if(nullptr == actor)
            return;
    }

    virtual void onExit(Actor* actor) override
    {

    }
};
    
template<typename Actor>
class FindingTargetState : public State<Actor>
{
public:
    FindingTargetState(int state_id) 
        :State<Actor>(state_id)
        ,found_target_(false)
        ,find_count_(0)
    {

    }
    
    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        found_target_ = findTarget(actor);
    }
    
    virtual void onUpdate(Actor* actor) override
    {
        if(nullptr == actor)
            return;
        
        // TODO : limit the time of finding target form cfg, 
        // if still not found target till the limit time, then change to idle state
        auto limit = 5;
        if (found_target_)
        {
            actor->set_pos_update_enabled(true);
            actor->state_machine()->changeState(StateIDs::NEARING_STATE);            
        }
        else if (find_count_ < limit)
        {
            found_target_ = findTarget(actor);
        }
        else
        {
            actor->state_machine()->changeState(StateIDs::IDLE_STATE);
        }
    }

    virtual void onExit(Actor* actor) override
    {
        found_target_ = false;
    }

private:
    typedef typename graph::NavGraphNode3D::Position Position3D;

    bool findTarget(Actor* actor)
    {
        find_count_++;

        auto space_partition = SceneManager::getInstance()->getSpacePartition();
        if (nullptr == space_partition)
            return false;

        // find targets
        Position3D self_pos = actor->getPosition();
        float query_radius = 200; // TODO : get query radius from cfg
        space_partition->calculateNeighbors(self_pos, query_radius);

        // find a target
        auto neighbors = space_partition->getAliveNeighbors(actor);
        if (neighbors.empty())
            return false;

        // TODO : sort neighbors by threat, and choose the high threat neighbor as target

        actor->set_target(neighbors[0]);

        // set path to target        
        Position3D src_pos = self_pos;
        Position3D tar_pos = getPositionForMoving(actor);

        auto sorce  = utils_graph::getNodeIndexByPos(src_pos);
        auto target = utils_graph::getNodeIndexByPos(tar_pos);

        auto path = PathFinder::getInstance()->doAStarSearch(sorce, target);
        actor->set_target_path(path);

        return true;
    }

    // get the pos to move 
    Position3D getPositionForMoving(Actor* actor)
    {
        Position3D move_pos;
        auto ent_target = actor->target()->entity();
        if (nullptr == ent_target)
            return move_pos;
        
        Position3D self_pos = actor->getPosition();
        Position3D tar_pos  = actor->target()->getPosition();
        float lerp_base     = 0.8f;
        float lerp_speed    = 0.02f;
        float distance_squared = 2500;
        int try_count          = 1;        

        while (try_count <= 5)
        {        
            move_pos = self_pos.lerp(tar_pos, lerp_base);
            if (tar_pos.distanceSquared(move_pos) <= distance_squared)
            {
                return move_pos;
            }
            lerp_base += lerp_speed;
            ++try_count;
        }

        return move_pos;
    }

    bool found_target_;

    int find_count_;
};
 
template<typename Actor>
class NearingState : public State<Actor>
{
public:
    NearingState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        ActionCommand<Actor> cmd(CommandIDs::CMD_ID_PLAY_ACTION);
        cmd.set_sub_command_id(CommandIDs::CMD_ID_PLAY_WALK_ACTION);
        cmd.set_initiator(actor);
        CommandManager::getInstance()->sendCmd(&cmd);

        // turn face to target
        auto target = actor->target();
        if (nullptr != target)
        {               
            auto tar_pos = target->getPosition();
            auto self_pos = actor->getPosition();

            cocos2d::Vec2 target_pos1 = cocos2d::Vec2(tar_pos.x, -tar_pos.z);
            cocos2d::Vec2 self_pos1 = cocos2d::Vec2(self_pos.x, -self_pos.z);
            cocos2d::Vec2 target_vec = target_pos1 - self_pos1;
            target_vec.normalize();
            float target_angle = atan2f(target_vec.y, target_vec.x);
            float target_degree = CC_RADIANS_TO_DEGREES(target_angle);    
            
            float cur_facing = actor->entity()->getRotation3D().y;
            float delta_degree = target_degree - cur_facing;
            delta_degree = (int)delta_degree % 360;
            bool anti_clockwise = (delta_degree - 180) < 0;
            if (anti_clockwise)
            {
                actor->entity()->setRotation3D(cocos2d::Vec3(0, target_degree + 90, 0));
            }            
            else
            {
                actor->entity()->setRotation3D(cocos2d::Vec3(0, -(360 - target_degree) + 90, 0));
            }
        }
    }

    virtual void onUpdate(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        auto target = actor->target();
        if (nullptr == target)
            return;

        typename graph::NavGraphNode3D::Position self_pos   = actor->getPosition();
        typename graph::NavGraphNode3D::Position target_path_last_pos = actor->target_path_last_pos();
        if (self_pos.distanceSquared(target_path_last_pos) <= 1)
        {
            actor->state_machine()->changeState(StateIDs::ATTACKING_STATE);
        }
    }

    virtual void onExit(Actor* actor) override
    {

    }
};

template<typename Actor>
class AttackingState : public State<Actor>
{
public:
    AttackingState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        sendAttackCmd(actor);

        auto target = actor->target();        
        if (nullptr != target)
        {
            target->state_machine()->changeState(StateIDs::BEING_ATTACKED_STATE);
        }
    }

    virtual void onUpdate(Actor* actor) override
    {
        if(nullptr == actor)
            return;

        auto target = actor->target();        
        if (nullptr != target)
        {
            //target->set_hp(target->hp() - 20);
            if (target->hp() > 0)
            {
                sendAttackCmd(actor);
            }
            else
            {
                actor->set_pos_update_enabled(false);
                actor->state_machine()->changeState(StateIDs::IDLE_STATE);
                actor->state_machine()->changeState(StateIDs::FINDING_TARGET_STATE);
                //actor->state_machine()->changeState(StateIDs::IDLE_STATE);
            }
        }
    }

    virtual void onExit(Actor* actor) override
    {

    }

private:
    void sendAttackCmd(Actor* actor)
    {
        AttackCommand<Actor> att_cmd(CommandIDs::CMD_ID_NORMAL_ATTACK);
        att_cmd.set_attacker(actor);
        att_cmd.set_target(actor->target());

        CommandManager::getInstance()->sendCmd(&att_cmd);
    }
};

template<typename Actor>
class BeingAttackedState : public State<Actor>
{
public:
    BeingAttackedState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        //actor->set_ai_enabled(true);
    }

    virtual void onUpdate(Actor* actor) override
    {
        if(nullptr == actor)
            return;

        //actor->set_hp(actor->hp() - 20);

        if (actor->hp() <= 0)
        {
            actor->state_machine()->changeState(StateIDs::DEAD_STATE);
        }
    }

    virtual void onExit(Actor* actor) override
    {

    }
};

template<typename Actor>
class DeadState : public State<Actor>
{
public:
    DeadState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        actor->set_ai_enabled(false);

        ActionCommand<Actor> cmd(CommandIDs::CMD_ID_PLAY_ACTION);
        cmd.set_sub_command_id(CommandIDs::CMD_ID_PLAY_DEAD_ACTION);
        cmd.set_initiator(actor);
        CommandManager::getInstance()->sendCmd(&cmd);
    }

    virtual void onUpdate(Actor* actor) override
    {
        if(nullptr == actor)
            return;
    }

    virtual void onExit(Actor* actor) override
    {

    }
};

} // namespace gamer 

#endif // CITY_HUNTER_SRC_ACTOR_STATES_H_