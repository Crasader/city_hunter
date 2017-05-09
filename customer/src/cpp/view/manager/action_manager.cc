/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  action_manager.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2016-03-29
 @ description:   see the header file.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#include "action_manager.h"

#include "audio/include/AudioEngine.h"

#include "action_command.h"
#include "attack_command.h"
#include "actor.h"
#include "actor_typedef.h"
#include "command_headers.h"
#include "data_manager.h"
#include "event.h"
#include "macros.h"

namespace gamer
{

ActionManager::ActionManager()
{

}

ActionManager::~ActionManager()
{

}

ActionManager* ActionManager::getInstance()
{
    //static ActionManager action_manager;
    //return &action_manager;

    static ActionManager* action_manager = nullptr;
    if (nullptr == action_manager)
    {
        action_manager = new ActionManager();
        if ( !action_manager->initListeners() )
        {
            SAFE_DELETE(action_manager); 
        }
    }
    return action_manager;
}

void ActionManager::destoryInstance()
{
    ActionManager* manager = ActionManager::getInstance();
    SAFE_DELETE(manager);
}

bool ActionManager::init()
{
    return true;
}

bool ActionManager::initListeners()
{
    //auto listener = gamer::CommandListener::create(
    //    CommandIDs::CMD_PLAY_ACTION, 
    //    CALLBACK_SELECTOR_1(ActionManager::onCommandReceived, this),
    //    "ActionManager::onCommandReceive", 
    //    1);
    //CommandManager::getInstance()->addCmdListener(listener);

    //listener = CommandListener::create(
    //    CommandIDs::CMD_NORMAL_ATTACK, 
    //    CALLBACK_SELECTOR_1(ActionManager::onCommandReceived, this),
    //    "ActionManager::onCommandReceive", 
    //    1);
    //CommandManager::getInstance()->addCmdListener(listener);

    return true;
}

void ActionManager::onCommandReceived(gamer::Command* cmd)
{
    //auto cmd_id = cmd->command_id();
    //auto sub_cmd_id = cmd->sub_command_id();
    //if (CommandIDs::CMD_PLAY_ACTION == cmd_id)
    //{
    //    dealWithPlayActionCommand(cmd);       
    //}
    //else if (CommandIDs::CMD_NORMAL_ATTACK == cmd_id)
    //{
    //    dealWithAttackCommand(cmd);
    //}
}

void ActionManager::dealWithPlayActionCommand(gamer::Command* cmd)
{
    //auto action_cmd = static_cast<ActionCommand<ActorType>*>(cmd);    
    //auto attacker   = action_cmd->attacker();
    //if (nullptr == attacker)
    //    return;

    //auto sub_cmd_id   = action_cmd->sub_command_id();
    //auto data_manager = DataManager::getInstance();
    //if (CommandIDs::CMD_PLAY_IDLE_ACTION == sub_cmd_id)
    //{
    //    attacker->playAction(data_manager->idle_action(), true);
    //}
    //else if (CommandIDs::CMD_PLAY_WALK_ACTION == sub_cmd_id)
    //{
    //    attacker->playAction(data_manager->walk_action(), true);
    //}
    //else if (CommandIDs::CMD_PLAY_DEAD_ACTION == sub_cmd_id)
    //{
    //    attacker->playAction(data_manager->dead_action(), false);
    //}
}

void ActionManager::dealWithAttackCommand(gamer::Command* cmd)
{
    //auto att_cmd      = static_cast<AttackCommand<ActorType>*>(cmd);
    //auto cmd_id       = att_cmd->command_id();
    //auto attacker     = att_cmd->attacker();
    //auto target       = att_cmd->target();
    //auto attacker_id  = attacker->id();
    //auto target_id    = target->id();
    //auto data_manager = DataManager::getInstance();

    //auto attack_action = data_manager->attack_action(attacker_id, cmd_id);
    //auto being_attacked_action = data_manager->attacked_action(target_id, cmd_id);

    //attacker->playAction(attack_action, false);
    ////target->playAction(being_attacked_action, false);

    //auto attack_audio = data_manager->attack_audio(attacker_id, cmd_id);
    //auto attacked_audio = data_manager->attacked_audio(attacker_id, cmd_id);
    //cocos2d::experimental::AudioEngine::play2d(attack_audio, false, 1);
    ////cocos2d::experimental::AudioEngine::play2d(attacked_audio, false, 1);

    //auto state_id = target->state_machine()->current_state_id();
    //auto actor_state_cfg = data_manager->actor_state_cfg();
    //for (auto i = 4; i < 8; i++)
    //{
    //    auto state_cfg = actor_state_cfg.state_cfg(i);
    //    auto stateid = state_cfg.state_id();
    //    if (state_id == stateid)
    //    {
    //        auto size = state_cfg.next_state_size();
    //        for (auto j = 0; j < size; j++)
    //        {
    //            auto id = state_cfg.next_state(j).state_id();
    //            auto requirement = state_cfg.next_state(j).state_change_requirement();
    //            auto r = (rand() % (10 - 1)) + 1;
    //            cocos2d::log("requirement : %d, r : %d", requirement, r);
    //            if (requirement == 3 && r <= 5)
    //            {                    
    //                target->state_machine()->changeState(id);
    //                target->playAction("knocked", false);
    //                cocos2d::experimental::AudioEngine::play2d(attacked_audio, false, 1);
    //                break;
    //            }
    //            if (requirement == 4)
    //            {
    //                target->state_machine()->changeState(id);
    //                target->playAction("defend", false);
    //                cocos2d::experimental::AudioEngine::play2d(attacked_audio, false, 1);
    //                break;
    //            }
    //        }

    //        break;
    //    }
    //}    
}

} // namespace gamer