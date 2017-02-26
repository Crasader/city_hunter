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
#include "command.h"
#include "command_constants.h"
#include "command_listener.h"
#include "command_manager.h"
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
        CommandIDs::CMD_ID_NORMAL_ATTACK, 
        std::bind(&HPManager::onCommandAttack, this, std::placeholders::_1),
        "HPManager::onCommandAttack", 
        1);
    gamer::CommandManager::getInstance()->addCmdListener(listener);

    return true;
}

void HPManager::onCommandAttack(gamer::Command* cmd)
{
    auto att_cmd  = static_cast<AttackCommand<ActorType>*>(cmd);
    auto attacker = att_cmd->attacker();
    auto target   = att_cmd->target();
    if (nullptr != target && nullptr != attacker)
    {
        target->set_hp(target->hp() - attacker->damage());
    }
}

bool HPManager::init()
{
    return true;
}

} // namespace gamer