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
#include "cocos/3d/CCSprite3D.h"

#include "actor.h"
#include "command.h"
#include "command_constants.h"
#include "command_listener.h"
#include "command_manager.h"
#include "event_define.h"
#include "event_manager.h"
#include "macros.h"
#include "protobuf/data_manager.h"
#include "protobuf/actor_cfg.pb.h"
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
        CommandIDs::CMD_ID_CREATE_ACTORS, 
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
    for (int i = 0; i < actor_cfg.actor_model_size(); i++)
    {
        auto actor_model = actor_cfg.actor_model(i);
        auto model_fiel  = actor_model.model_file();
        auto pos         = actor_model.position();
        auto rotation    = actor_model.rotation();
        auto actor       = ActorType::create(model_fiel);
        if (nullptr != actor && actor->entity())
        {
            scene->addChild(actor->entity());
            
            actor->set_id(actor_model.id());                    

            actor->entity()->setScale(actor_model.scale());
            actor->entity()->setPosition3D(cocos2d::Vec3(pos.x(), pos.y(), pos.z()));
            actor->entity()->setRotation3D(cocos2d::Vec3(rotation.x(), rotation.y(), rotation.z()));

            for (int j = 0; j < actor_model.action_size(); j++)
            {
                actor->addAction(actor_model.action(j).name(), 
                                 model_fiel, 
                                 actor_model.action(j).from_time(), 
                                 actor_model.action(j).duration(), 
                                 actor_model.action(j).speed());
            }

            created_actors_.insert(std::make_pair(actor->id(), actor));
        }

        if (0 == i)
        {
            actor->state_machine()->changeState(StateIDs::FINDING_TARGET_STATE);
        }
        else
        {
            actor->state_machine()->changeState(StateIDs::IDLE_STATE);
        }
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
    
    EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ID_ACTORS_CREATED);
}

bool ActorManager::init()
{
    return true;
}

} // namespace gamer