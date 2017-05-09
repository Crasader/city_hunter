/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  hp_manager.h
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

#include "hp_manager.h"

#include "attack_command.h"
#include "actor.h"
#include "actor_typedef.h"
#include "command_headers.h"
#include "macros.h"

namespace gamer
{

HPManager::HPManager()
{

}

HPManager::~HPManager()
{

}

HPManager* HPManager::getInstance()
{
    static HPManager* hp_manager = nullptr;
    if (nullptr == hp_manager)
    {
        hp_manager = new HPManager();
        if ( !hp_manager->initListeners() )
        {
            SAFE_DELETE(hp_manager); 
        }
    }
    return hp_manager;
}

void HPManager::destoryInstance()
{
    auto instance = HPManager::getInstance();
    SAFE_DELETE(instance);
}

bool HPManager::initListeners()
{
    auto listener = gamer::CommandListener::create(
        CommandIDs::CMD_ATTACK, 
        std::bind(&HPManager::onCommandAttack, this, std::placeholders::_1),
        "HPManager::onCommandAttack", 
        (int)gamer::Listener::ListenerPriorities::NORMAL);
    gamer::CommandManager::getInstance()->addCmdListener(listener);

    return true;
}

void HPManager::onCommandAttack(gamer::Command* cmd)
{
    auto actor = static_cast<gamer::ActorType*>(cmd->user_data());
    auto target = actor->target();
    if (nullptr != actor && nullptr != target)
    {
        target->set_hp(target->hp() - actor->damage());
    }
}

bool HPManager::init()
{
    return true;
}

} // namespace gamer