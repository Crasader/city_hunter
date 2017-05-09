/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  actor_manager.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-11-01
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "actor_manager.h"

#include <string>

#include "cocos2d.h"

#include "actor.h"
#include "command_headers.h"
#include "event_headers.h"
#include "data_manager.h"
#include "macros.h"
#include "map_cfg.pb.h"
#include "scene_manager.h"

namespace gamer
{

ActorManager::ActorManager()
{

}

ActorManager::~ActorManager()
{

}

ActorManager* ActorManager::getInstance()
{
    static ActorManager* actor_manager = nullptr;
    if (nullptr == actor_manager)
    {
        actor_manager = new ActorManager();
        if ( !actor_manager->initListeners() )
        {
            SAFE_DELETE(actor_manager); 
        }
    }
    return actor_manager;
}

bool ActorManager::initListeners()
{
    auto listener = gamer::CommandListener::create(
        CommandIDs::CMD_CREATE_ACTORS, 
        std::bind(&ActorManager::onCommandCreateActors, this, std::placeholders::_1),
        "ActorManager::onCommandCreateActors", 
        1);
    CommandManager::getInstance()->addCmdListener(listener);

    return true;
}

void ActorManager::onCommandCreateActors(gamer::Command* cmd)
{
    auto scene = SceneManager::getInstance()->cur_scene();
    if (nullptr == scene)
        return;

    auto actor_cfg = DataManager::getInstance()->actor_cfg();
    auto model_cfg = DataManager::getInstance()->model_cfg();
    auto action_cfg = DataManager::getInstance()->action_cfg();
    for (auto i = 0; i < actor_cfg.actor_size(); i++)
    {
        auto actorcfg = actor_cfg.actor(i);
        auto model_file  = model_cfg.model(actorcfg.model_id()).file();
        auto pos         = actorcfg.position();
        auto rotation    = actorcfg.rotation();
        auto actor       = ActorType::create(model_file);
        if (nullptr != actor && actor->entity())
        {
            scene->addChild(actor->entity());
            
            actor->set_id(actorcfg.id());
            actor->set_actor_type(actorcfg.actor_type());
            actor->entity()->setScale(actorcfg.scale());
            actor->entity()->setPosition3D(cocos2d::Vec3(pos.x(), pos.y(), pos.z()));
            actor->entity()->setRotation3D(cocos2d::Vec3(rotation.x(), rotation.y(), rotation.z()));
            // TODO : cfg ai update interval
            auto actions = action_cfg.actor_action(actorcfg.actor_type());
            for (int j = 0; j < actions.action_size(); j++)
            {
                actor->addAction((int)actions.action(j).id(),
                                 model_file, 
                                 actions.action(j).from_time(),
                                 actions.action(j).duration(),
                                 actions.action(j).speed());
            }

            created_actors_.insert(std::make_pair(actor->id(), actor));
        }

        actor->state_machine()->changeState(actorcfg.first_state_id());
    }
    
    // add actors to space
    auto space = SceneManager::getInstance()->getSpacePartition();
    if (nullptr != space)
    {
        std::for_each(created_actors_.begin(), 
                      created_actors_.end(), 
                      [&](std::pair<int, ActorType*> a)
                      { 
                          space->addEntity(a.second);
                      });
    }
    
    EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ACTORS_CREATED);
}

bool ActorManager::init()
{
    return true;
}

} // namespace gamer