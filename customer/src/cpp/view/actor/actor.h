/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  actor.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-08-15
  @ description:  role base class.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_ACTOR_H_
#define CITY_HUNTER_SRC_ACTOR_H_

#include <functional>
#include <list>
#include <map>
#include <string>

#include "cocos2d.h"

#include "actor_interface.h"
#include "actor_states.h"
#include "game_object.h"
#include "graph_typedef.h"
#include "id_provider.h"
#include "macros.h"
#include "path_finder.h"
#include "state.h"
#include "state_constants.h"
#include "state_machine.h"
#include "util.h"
#include "util_graph.h"
// TODO : deal with header

namespace gamer
{

// common role base class
template<typename Entity>
class Actor : public Actor_Interface, public GameObject
{
public:
    virtual ~Actor()
    {
        SAFE_DELETE(state_machine_);
    }
    
    static Actor<Entity>* create(const std::string& model_path)
    {
        auto actor = new Actor<Entity>();
        if (actor && actor->init(model_path))
        {
            return actor;
        }
        SAFE_DELETE(actor);
        return nullptr;
    }

    Entity* entity() const
    {
        return entity_;
    }
      
    const std::string name() const
    {
        return name_;
    }
    
    void set_name(const std::string& name)
    {
        name_ = name;
    }
    
    virtual void addAction(int action_id, 
                           const std::string& file, 
                           float from_time, 
                           float duration, 
                           float speed) override
    {

    }
    
    virtual void playAction(int action_id, bool loop) override
    {

    }
    
    inline void set_actor_type(int actor_type) override 
    { 
        actor_type_ = actor_type; 
    }

    inline int actor_type() const override { return actor_type_; }

    inline virtual void set_hp(int hp) override
    {
        hp_ = hp;
    }

    inline virtual int hp() const override
    {
        return hp_;
    }

    inline virtual void set_damage(int damage) override { damage_ = damage; }

    inline virtual int damage() const override { return damage_; }

    graph::NavGraphNode3D::Position getPosition() const
    {
        if (nullptr != entity_)
            return entity_->getPosition3D();
        return graph::NavGraphNode3D::Position();
    }

    void setPosition(graph::NavGraphNode3D::Position& pos)
    {
        if (nullptr != entity_)
        {
            entity_->setPosition3D(pos);
        }
    }

    // finite state machine
    FSM<Actor<Entity> >* state_machine() const
    {
        return state_machine_;
    }
    
    void onAIUpdate(float dt)
    {
        
    }
    
    void onPositionUpdate(float dt)
    {

    }
    
    inline void set_ai_enabled(bool enabled)
    {
        ai_enabled_ = enabled;
    }
    
    inline bool ai_enabled() const
    {
        return ai_enabled_;
    }
    
    inline void set_ai_update_interval(float interval)
    {

    }
    
    inline void set_target_path(graph::PathNodes& path)
    {
        path_ = path;
    }
    
    inline graph::PathNodes target_path() const
    {
        return path_;
    }
    
protected:
    bool init(const std::string& model_path)
    {
        return true;
    }
    
private:
    Actor()
        :GameObject(IDProvider::getNextID())
        , entity_(nullptr)
        , state_machine_(nullptr)
        , ai_enabled_(true)
        , ai_update_interval_(1.0f)
        , speed_(0.2f)
        , lerp_alpha_(0.2f)
        , hp_(100)
        , damage_(10)
    {

    }

    Actor(float ai_update_interval)
        :GameObject(IDProvider::getNextID())
        , entity_(nullptr)
        , state_machine_(nullptr)
        , ai_enabled_(true)
        , ai_update_interval_(ai_update_interval)
        , speed_(0.2f)
        , lerp_alpha_(0.2f)
        , hp_(100)
        , damage_(10)
    {

    }

    Entity* entity_;    
    std::string name_;
    FSM<Actor>* state_machine_;
    bool ai_enabled_;
    float ai_update_interval_;
    std::list<int> path_; // the path that store node indexes
    std::list<int>::iterator iter_src_node_; 
    std::list<int>::iterator iter_target_node_;
    
    float lerp_alpha_;
    
    float speed_;

    int actor_type_;
    int hp_;
    int damage_;
};

// partition specialization of role base class for cocos 3d
template<>
class Actor<cocos2d::Sprite3D> : public Actor_Interface, public GameObject
{
public:
    virtual ~Actor() 
    {
        SAFE_DELETE(state_machine_);
    }

    static ActorType* create(const std::string& model_path)
    {
        auto actor = new ActorType();
        if (actor && actor->init(model_path))
        {
            return actor;
        }
        SAFE_DELETE(actor);
        return nullptr;
    }

    void onAIUpdate(float dt)
    {
        //cocos2d::log("onAIUpdate : %f", dt);
        if ( !ai_enabled_ || nullptr == state_machine_ )
            return;
        state_machine_->update();
    }

    void onPositionUpdate(float dt)
    {
        //cocos2d::log("onPositionUpdate : %f", dt);
        if (!ai_enabled_ || !pos_update_enabled_ || nullptr == entity_)
            return;

        if (path_.empty() || path_.end() == iter_target_node_)
            return;

        // TODO £ºcfg attack distance
        auto target_actor_pos = this->target()->entity()->getPosition3D();
        if (entity_->getPosition3D().distanceSquared(target_actor_pos) < 6400)
        {
            this->stop_position_update();
            return;
        }

        auto graph = PathFinder::getInstance()->graph();
        auto target_node = graph->getNode(*iter_target_node_);

        auto target_pos = target_node.position();
        auto actor_pos = entity_->getPosition3D();
        auto next_pos = src_pos_.lerp(target_pos, lerp_alpha_);

        if (next_pos.distanceSquared(target_pos) <= 0.2f)
        {
            if (!target_node.enabled())
            {
                path_ = PathFinder::getInstance()->doAStarSearch(*iter_src_node_, path_.back());

                iter_src_node_ = path_.begin();
                iter_target_node_ = iter_src_node_;
                ++iter_target_node_;

                src_pos_ = actor_pos;

                // test 
                /*
                auto draw_node = gamer::SceneManager::getInstance()->draw_node_3d();
                gamer::util_graph::drawPath(path_,
                *graph,
                *draw_node,
                cocos2d::Color4F::WHITE);
                */
                lerp_alpha_ = speed_;
            }
            else
            {
                entity_->setPosition3D(next_pos);

                target_node.set_enabled(false);

                if (iter_target_node_ != iter_src_node_)
                {
                    auto src_node = graph->getNode(*iter_src_node_);
                    src_node.set_enabled(true);
                }

                iter_src_node_ = iter_target_node_;
                ++iter_target_node_;

                src_pos_ = next_pos;

                lerp_alpha_ += speed_;
                if (lerp_alpha_ > 1.0f)
                {
                    lerp_alpha_ = speed_;
                }
            }
        }
        else
        {
            entity_->setPosition3D(next_pos);

            lerp_alpha_ += speed_;
            if (lerp_alpha_ > 1.0f)
            {
                lerp_alpha_ = speed_;
            }
        }
    }

    // TODO : add action to action manager
    virtual void addAction(int action_id,
                           const std::string& file, 
                           float from_time, 
                           float duration, 
                           float speed) override
    {
        auto animation3d = cocos2d::Animation3D::create(file); // it will be cached in Animation3DCache Instance
        if (nullptr != animation3d)
        {
            auto animate3d = cocos2d::Animate3D::create(animation3d, from_time, duration); // it will not be cached 
            animate3d->setSpeed(speed);
            animate3d->retain();

            actions_map_.insert(std::make_pair(action_id, animate3d));
        }
    }

    virtual void playAction(int action_id, bool loop) override
    {
        auto animate3d = actions_map_.find(action_id);
        if (actions_map_.end() == animate3d)
            return;

        entity_->stopAllActions();
        if (loop)
        {
            entity_->runAction(cocos2d::RepeatForever::create(animate3d->second));
        }
        else
        {
            entity_->runAction(animate3d->second);
        }
    }

    cocos2d::Vec3 getPosition() const
    {
        if (nullptr != entity_)
            return entity_->getPosition3D();
        return cocos2d::Vec3();
    }

    void setPosition(cocos2d::Vec3& pos)
    {
        if (nullptr != entity_)
        {
            entity_->setPosition3D(pos);
        }
    }

    inline FSM<ActorType>* state_machine() const { return state_machine_; }

    inline void set_actor_type(int actor_type) override
    {
        actor_type_ = actor_type;
    }

    inline int actor_type() const override { return actor_type_; }

    inline void set_hp(int hp) override { hp_ = hp; }

    inline int hp() const override { return hp_; }

    inline virtual void set_damage(int damage) override { damage_ = damage; }

    inline virtual int damage() const override { return damage_; }

    inline cocos2d::Sprite3D* entity() const { return entity_; }

    inline std::string name() const { return name_; }

    inline void set_name(const std::string& name) { name_ = name; }

    inline void set_ai_enabled(bool enabled) { ai_enabled_ = enabled; }

    inline bool ai_enabled() const { return ai_enabled_; }

    inline void set_pos_update_enabled(bool enabled) { pos_update_enabled_ = enabled; }

    inline bool pos_update_enabled() const { return pos_update_enabled_; }

    inline void start_position_update() 
    { 
        if ( !entity_->isScheduled("position_update_callback") )
        {
            entity_->schedule([&](float dt) { this->onPositionUpdate(dt); },
                "position_update_callback");            
        }
        pos_update_enabled_ = true;
    }

    inline void stop_position_update() 
    { 
        entity_->unschedule("position_update_callback");
        pos_update_enabled_ = false;
    }

    inline void set_ai_update_interval(float interval)
    {
        entity_->unschedule("ai_update_callback");        
        entity_->schedule([&](float dt){ this->onAIUpdate(dt); }, interval, "ai_update_callback");        
        ai_update_interval_ = interval;
    }
    
    inline void start_ai_update()
    {
        ai_enabled_ = true;
        if (!entity_->isScheduled("ai_update_callback"))
        {
            entity_->schedule([&](float dt) { this->onAIUpdate(dt); },
                              ai_update_interval_,
                              "ai_update_callback");
        }        
    }

    inline void stop_ai_update()
    {
        entity_->unschedule("ai_update_callback");
        ai_enabled_ = false;
    }

    inline void set_target_path(graph::PathNodes& path)
    {
        path_ = path;

        if (path.empty())
            return;
        
        iter_src_node_ = path_.begin();
        iter_target_node_ = iter_src_node_;
        ++iter_target_node_;

        auto graph = PathFinder::getInstance()->graph();
        src_pos_ = graph->getNode(*iter_src_node_).position();
    }
    
    inline graph::PathNodes target_path() const { return path_; }
    
    inline cocos2d::Vec3 target_path_last_pos() const
    {
        if (path_.empty())
            return cocos2d::Vec3();

        auto graph = PathFinder::getInstance()->graph();
        return graph->getNode(path_.back()).position();
    }

    inline void set_target(ActorType* target) { target_ = target; }
    
    inline ActorType* target() const { return target_; }

protected:
    bool init(const std::string& model_path)
    {
        // create visual obj
        entity_ = cocos2d::Sprite3D::create(model_path);
        if (nullptr == entity_)
            return false;

        // init base  attribute
        hp_ = 100; // TODO : read from cfg
        
        state_machine_ = new FSM<ActorType>(this);

        if (ai_enabled_)
        {
            this->start_ai_update();
        }

        return true;
    }

private:      
    Actor() : Actor(1.5f) {}

    Actor(float ai_update_interval)
        :GameObject(IDProvider::getNextID())
        ,entity_(nullptr)
        ,state_machine_(nullptr)
        ,ai_enabled_(true)
        ,pos_update_enabled_(false)
        ,ai_update_interval_(ai_update_interval)
        ,speed_(0.2f)
        ,lerp_alpha_(0.2f) 
        ,hp_(100)
        ,damage_(10)
    {

    }

    cocos2d::Sprite3D* entity_;
    
    std::string name_;
    
    std::map<int, cocos2d::Animate3D*> actions_map_;
    
    FSM<ActorType>* state_machine_;
    
    bool ai_enabled_;
    bool pos_update_enabled_;
    float ai_update_interval_;
    
    graph::PathNodes path_; // path to target
    graph::PathNodes::iterator iter_src_node_;
    graph::PathNodes::iterator iter_target_node_;

    cocos2d::Vec3 src_pos_;

    float lerp_alpha_;
    float speed_;
    
    ActorType* target_;

    int actor_type_;
    int hp_;
    int damage_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_ACTOR_H_