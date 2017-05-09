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

#include "battle_manager.h"
#include "command_headers.h"
#include "event_headers.h"
#include "game_object.h"
#include "graph_typedef.h"
#include "path_finder.h"
#include "state.h"
#include "state_constants.h"
#include "util_graph.h"
#include "util_actor.h"
// TODO : ugly, deal with included header

namespace gamer
{
    
template<typename Actor>
class IdleState : public State<Actor>
{
public:
    IdleState() = delete;

    IdleState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if(nullptr == actor)
            return;

        EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ACTOR_ENTERED_STATE, actor);
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
    FindingTargetState() = delete;

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
            actor->start_position_update();
            actor->state_machine()->changeState(StateIDs::NEARING_TARGET_STATE);            
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

        auto sorce  = util_graph::getNodeIndexByPos(src_pos);
        auto target = util_graph::getNodeIndexByPos(tar_pos);

        auto path = PathFinder::getInstance()->doAStarSearch(sorce, target);
        actor->set_target_path(path);

        return true;
    }

    // TODO : ugly
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
    NearingState() = delete;

    NearingState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ACTOR_ENTERED_STATE, actor);

        // turn face to target
        auto target = actor->target();
        if (nullptr != target)
        {   
            util_actor::turnFace2Target(actor, target);
        }
    }

    virtual void onUpdate(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        auto target = actor->target();
        if (nullptr == target)
            return;

        auto self_pos   = actor->getPosition();
        auto target_pos = target->getPosition();
        //auto target_path_last_pos = actor->target_path_last_pos(); // TODO : move this func to util
        // TODO : read from cfg
        if (self_pos.distanceSquared(target_pos) <= 6400) // TODO : attack arrange
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
    AttackingState() = delete;

    AttackingState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        util_actor::turnFace2Target(actor, actor->target());
        actor->target()->set_target(actor);
        CommandManager::getInstance()->sendCmd(CommandIDs::CMD_ATTACK, actor);
    }

    virtual void onUpdate(Actor* actor) override
    {
        if(nullptr == actor)
            return;

        if (actor->target()->hp() <= 0)
        {
            actor->state_machine()->changeState(StateIDs::IDLE_STATE);
        }
        else
        {
            CommandManager::getInstance()->sendCmd(CommandIDs::CMD_ATTACK, actor);
        }
    }

    virtual void onExit(Actor* actor) override
    {

    }

private:
};

template<typename Actor>
class BeingAttackedState : public State<Actor>
{
public:
    BeingAttackedState() = delete;

    BeingAttackedState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;
        EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ACTOR_ENTERED_STATE, actor);
    }

    virtual void onUpdate(Actor* actor) override
    {
        if(nullptr == actor)
            return;

        if (actor->hp() <= 0)
        {
            actor->state_machine()->changeState(StateIDs::DEAD_STATE);
        }
        BattleManager::getInstance()->dealWithNextState(actor);
    }

    virtual void onExit(Actor* actor) override
    {

    }
};

template<typename Actor>
class DefendingState : public State<Actor>
{
public:
    DefendingState() = delete;

    DefendingState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;
        EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ACTOR_ENTERED_STATE, actor);
    }

    virtual void onUpdate(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        if (actor->hp() <= 0)
        {
            actor->state_machine()->changeState(StateIDs::DEAD_STATE);
        }
        BattleManager::getInstance()->dealWithNextState(actor);
    }

    virtual void onExit(Actor* actor) override
    {

    }
};

template<typename Actor>
class DeadState : public State<Actor>
{
public:
    DeadState() = delete;

    DeadState(int state_id) : State<Actor>(state_id) {}

    virtual void onEnter(Actor* actor) override
    {
        if (nullptr == actor)
            return;

        EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ACTOR_ENTERED_STATE, actor);

        actor->stop_position_update();
        actor->stop_ai_update();
    }

    virtual void onUpdate(Actor* actor) override
    {

    }

    virtual void onExit(Actor* actor) override
    {

    }
};

} // namespace gamer 

#endif // CITY_HUNTER_SRC_ACTOR_STATES_H_