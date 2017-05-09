/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  battle_manager.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2017-04-12
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "battle_manager.h"

#include "audio/include/AudioEngine.h"

#include "attack_command.h"
#include "actor.h"
#include "actor_typedef.h"
#include "command_headers.h"
#include "event_headers.h"
#include "data_manager.h"
#include "macros.h"

namespace gamer
{

BattleManager::BattleManager()
{

}

BattleManager::~BattleManager()
{

}

BattleManager* BattleManager::getInstance()
{
    static BattleManager* battle_manager = nullptr;
    if (nullptr == battle_manager)
    {
        battle_manager = new BattleManager();
        if ( !battle_manager->initListeners() )
        {
            SAFE_DELETE(battle_manager); 
        }
    }
    return battle_manager;
}

void BattleManager::destoryInstance()
{
    auto instance = BattleManager::getInstance();
    SAFE_DELETE(instance);
}

bool BattleManager::init()
{
    return true;
}

bool BattleManager::initListeners()
{
    auto l1 = CommandListener::create(
        CommandIDs::CMD_ATTACK, 
        std::bind(&BattleManager::onCommandReceived, this, std::placeholders::_1),
        "BattleManager::onCommandReceived", 
        (int)Listener::ListenerPriorities::SENIOR);
    CommandManager::getInstance()->addCmdListener(l1);

    auto l2 = EventListener::create(
        EventIDs::EVENT_ACTOR_ENTERED_STATE,
        std::bind(&BattleManager::onEventReceived, this, std::placeholders::_1),
        "BattleManager::onEventReceived",
        (int)Listener::ListenerPriorities::SENIOR);
    EventManager::getInstance()->addEventListener(l2);

    return true;
}

void BattleManager::onCommandReceived(gamer::Command* cmd)
{
    switch (cmd->command_id())
    {
    case CommandIDs::CMD_ATTACK:
        this->dealWithAttackCommand(cmd);
        break;
    default:
        break;
    }
}

void BattleManager::onEventReceived(gamer::Event* event)
{
    switch (event->event_id())
    {
    case EventIDs::EVENT_ACTOR_ENTERED_STATE:
        this->dealWithActorEnteredState(event);
        break;
    default:
        break;
    }
}

void BattleManager::dealWithAttackCommand(gamer::Command* cmd)
{
    auto actor       = static_cast<gamer::ActorType*>(cmd->user_data());
    auto target      = actor->target();
    auto actor_type1 = actor->actor_type();
    auto actor_type2 = target->actor_type();
    auto data_mgr    = DataManager::getInstance();
    auto action_id1  = data_mgr->getNormalAttackActionID(actor_type1);
    auto action_id2  = data_mgr->getNormalHurtActionID(actor_type2);
    
    actor->set_ai_enabled(false);
    actor->playAction(action_id1, false);
    
    auto audio1 = data_mgr->getNormalAttackAudio(actor_type1);
    auto audio2 = data_mgr->getNormalHurtAudio(actor_type2);

    cocos2d::experimental::AudioEngine::play2d(audio1, false, 1);
    cocos2d::experimental::AudioEngine::play2d(audio2, false, 1);
    
    //cocos2d::log("cur_state_id  :  %d", target->state_machine()->current_state_id());
    
    this->dealWithNextState(target);

    actor->set_ai_update_interval(2);
    target->set_ai_update_interval(1.5f);
}

void BattleManager::dealWithActorEnteredState(gamer::Event* event)
{
    auto actor        = static_cast<gamer::ActorType*>(event->user_data());    
    auto state_id     = actor->state_machine()->current_state_id();
    auto actor_type   = actor->actor_type();
    auto data_manager = DataManager::getInstance();
    
    switch (state_id)
    {
    case StateIDs::IDLE_STATE:
        {
            auto idle_action = data_manager->getIdleActionID(actor_type);
            actor->playAction(idle_action, true);
        }
        break;
    case StateIDs::NEARING_TARGET_STATE:
        {
            auto nearing_action = data_manager->getNearingActionID(actor_type);
            actor->playAction(nearing_action, true);
        }
        break;
    case StateIDs::DEAD_STATE:
        {
            auto dead_action = data_manager->getDeadActionID(actor_type);
            actor->playAction(dead_action, false);
        }
        break;
    case StateIDs::DEFENDING_STATE:
        {
            auto defend_action = data_manager->getDefendingActionID(actor_type);
            actor->playAction(defend_action, false);
        }
        break;
    case StateIDs::BEING_ATTACKED_STATE:
        {
            auto hurt_action = data_manager->getNormalHurtActionID(actor_type);
            actor->playAction(hurt_action, false);
        }
        break;
    default:
        break;
    }
}

void BattleManager::dealWithNextState(ActorType* actor)
{
    auto actor_type     = actor->actor_type();
    auto cur_state_id   = actor->state_machine()->current_state_id();
    auto state_cfg_list = DataManager::getInstance()->actor_state_cfg();
    // TODO : ugly cfg, change it
    for (auto i = 0; i < state_cfg_list.state_cfg_size(); i++)
    {
        auto state_cfg = state_cfg_list.state_cfg(i);
        if (actor_type == state_cfg.actor_type() &&
            cur_state_id == state_cfg.state_id())
        {
            auto size = state_cfg.next_state_size();
            for (auto j = 0; j < size; j++)
            {
                auto id = state_cfg.next_state(j).state_id();
                auto requirement = state_cfg.next_state(j).state_change_requirement();                
                // TODO : use util func, use C++ 11 to for rand
                auto r = (rand() % (10 - 1)) + 1;
                //cocos2d::log("requirement : %d, r : %d", requirement, r);
                if (requirement == gamer::cfg::StateChangeRequirements::RANDOM1 && r <= 5)
                {
                    actor->set_ai_enabled(true);
                    if (actor->state_machine()->current_state_id() == id)
                    {
                        EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ACTOR_ENTERED_STATE, actor);
                    }
                    else
                    {
                        actor->state_machine()->changeState(id);
                    }                                       
                    break;
                }
                else if (requirement == gamer::cfg::StateChangeRequirements::RANDOM2)
                {
                    actor->set_ai_enabled(true);
                    if (actor->state_machine()->current_state_id() == id)
                    {
                        EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ACTOR_ENTERED_STATE, actor);
                    }
                    else
                    {
                        actor->state_machine()->changeState(id);
                    }
                    break;
                }
                else if (requirement == gamer::cfg::StateChangeRequirements::NO_REQUIREMENT)
                {
                    actor->set_ai_enabled(true);
                    if (actor->state_machine()->current_state_id() == id)
                    {
                        EventManager::getInstance()->dispatchEvent(EventIDs::EVENT_ACTOR_ENTERED_STATE, actor);
                    }
                    else
                    {
                        actor->state_machine()->changeState(id);
                    }
                    break;
                }
            }
            break;
        }
    }
}

} // namespace gamer