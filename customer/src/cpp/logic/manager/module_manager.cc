/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  module_manager.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-04-05
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "module_manager.h"

#include "actor_manager.h"
#include "action_manager.h"
#include "command_manager.h"
#include "camera_manager.h"
#include "effect_manager.h"
#include "hp_manager.h"
#include "macros.h"
#include "path_finder.h"
#include "protobuf/data_manager.h"
#include "scene_manager.h"

namespace gamer
{

ModuleManager::ModuleManager()
{

}

ModuleManager::~ModuleManager()
{

}

ModuleManager* ModuleManager::getInstance()
{
    static ModuleManager* module_manager = nullptr;
    if (nullptr == module_manager)
    {
        module_manager = new ModuleManager();
        if ( !module_manager->init() )
        {
            SAFE_DELETE(module_manager); 
        }
    }
    return module_manager;
}

void ModuleManager::initAllModules()
{
    gamer::SceneManager::getInstance()->init();

    gamer::CameraManager::getInstance()->init();

    gamer::ActorManager::getInstance()->init();

    gamer::PathFinder::getInstance()->init();

    gamer::ActionManager::getInstance()->init();

    gamer::HPManager::getInstance()->init();

    gamer::EffectManager::getInstance()->init();

    gamer::DataManager::getInstance()->init();
}

bool ModuleManager::init()
{
    return true;
}

} // namespace gamer