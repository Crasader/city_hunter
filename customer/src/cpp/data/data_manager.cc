/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  data_manager.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-11-09
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "data_manager.h"

#include <fstream>

#include "macros.h"
#include "cocos2d.h"
#include "state_constants.h"

using namespace gamer::cfg;

namespace gamer
{

DataManager::DataManager()
    :is_init_ok_(false)
{

}

DataManager::~DataManager()
{

}

DataManager* DataManager::getInstance()
{
    static DataManager* data_manager = nullptr;
    if (nullptr == data_manager)
    {
        data_manager = new DataManager();
        if ( !data_manager->init() )
        {
            SAFE_DELETE(data_manager); 
        }
    }
    return data_manager;
}

bool DataManager::init()
{
    if ( !is_init_ok_ )
    {
        GOOGLE_PROTOBUF_VERIFY_VERSION;  

        // map cfg
        auto path = cocos2d::FileUtils::getInstance()->fullPathForFilename("HelloWorld.png");
        auto i = path.rfind("/");
        auto res_root = path.substr(0, i + 1);
        auto map_cfg_path = res_root + "cfg//map_cfg.pb";
        std::fstream input(map_cfg_path.c_str(), std::ios::in | std::ios::binary);        
        if (!map_cfg_.ParseFromIstream(&input))
        {
            assert("read MapCfg failed !");
        }

        auto actor_cfg_path = res_root + "cfg//actor_cfg.pb";
        std::fstream input1(actor_cfg_path.c_str(), std::ios::in | std::ios::binary);
        if (!actor_cfg_.ParseFromIstream(&input1))
        {
            assert("read ActorCfg failed !");
        }

        // audio cfg
        auto audio_cfg_path = res_root + "cfg//audio_cfg.pb";
        std::fstream input2(audio_cfg_path.c_str(), std::ios::in | std::ios::binary);
        if (!audio_cfg_.ParseFromIstream(&input2))
        {
            assert("read AudioCfg failed !");
        }

        // camera cfg
		auto camer_cfg_path = res_root + "cfg//camera_cfg.pb";
		std::fstream input3(camer_cfg_path.c_str(), std::ios::in | std::ios::binary);
		if (!camera_cfg_.ParseFromIstream(&input3))
		{
			assert("read CameraCfg failed !");
		}

        // actor state cfg
        auto actor_state_cfg_path = res_root + "cfg//actor_state_cfg.pb";
        std::fstream input4(actor_state_cfg_path.c_str(), std::ios::in | std::ios::binary);
        if (!actor_state_cfg_.ParseFromIstream(&input4))
        {
            assert("read ActorStateCfg failed !");
        }

        // action cfg
        auto action_cfg_path = res_root + "cfg//action_cfg.pb";
        std::fstream input5(action_cfg_path.c_str(), std::ios::in | std::ios::binary);
        if (!action_cfg_.ParseFromIstream(&input5))
        {
            assert("read ActionCfg failed !");
        }

        // model cfg
        auto model_cfg_path = res_root + "cfg//model_cfg.pb";
        std::fstream input6(model_cfg_path.c_str(), std::ios::in | std::ios::binary);
        if (!model_cfg_.ParseFromIstream(&input6))
        {
            assert("read ModelCfg failed !");
        }

        is_init_ok_ = true;
    }
    return true;
}

const Action& DataManager::getAction(int actor_type, int action_id) const
{
    auto actions = action_cfg_.actor_action(actor_type);
    for (auto i = 0; i < actions.action_size(); i++)
    {
        if (actions.action(i).id() == action_id)
        {
            return actions.action(i);
        }
    }
    
    return actions.action(0);
}

ActionIDs DataManager::getEnterActionID(int actor_type, int state_id) const
{
    switch (actor_type)
    {
    case ActorTypes::ACTOR_HERO_KNIGHT:
        if (state_id == (int)StateIDs::IDLE_STATE)
        {
            return ActionIDs::ACTION_HERO_KNIGHT_IDLE;
        }
        else if (state_id == (int)StateIDs::NEARING_TARGET_STATE)
        {
            return ActionIDs::ACTION_HERO_KNIGHT_WALK;
        }
        else if (state_id == (int)StateIDs::ATTACKING_STATE)
        {
            return ActionIDs::ACTION_HERO_KNIGHT_NORMAL_ATK1;
        }
        else if (state_id == (int)StateIDs::BEING_ATTACKED_STATE)
        {
            return ActionIDs::ACTION_HERO_KNIGHT_HURT1;
        }
        else if (state_id == (int)StateIDs::DEFENDING_STATE)
        {
            return ActionIDs::ACTION_HERO_KNIGHT_DEFEND;
        }
        break;
    case ActorTypes::ACTOR_HERO_ARCHER:
        if (state_id == (int)StateIDs::IDLE_STATE)
        {
            return ActionIDs::ACTION_HERO_ARCHER_IDLE;
        }
        else if (state_id == (int)StateIDs::NEARING_TARGET_STATE)
        {
            return ActionIDs::ACTION_HERO_ARCHER_WALK;
        }
        else if (state_id == (int)StateIDs::ATTACKING_STATE)
        {
            return ActionIDs::ACTION_HERO_ARCHER_NORMAL_ATK1;
        }
        else if (state_id == (int)StateIDs::BEING_ATTACKED_STATE)
        {
            return ActionIDs::ACTION_HERO_ARCHER_HURT1;
        }
        else if (state_id == (int)StateIDs::DEFENDING_STATE)
        {
            return ActionIDs::ACTION_HERO_ARCHER_DEFEND;
        }
        break;
    case ActorTypes::ACTOR_HERO_MAGE:
        if (state_id == (int)StateIDs::IDLE_STATE)
        {
            return ActionIDs::ACTION_HERO_MAGE_IDLE;
        }
        else if (state_id == (int)StateIDs::NEARING_TARGET_STATE)
        {
            return ActionIDs::ACTION_HERO_MAGE_WALK;
        }
        else if (state_id == (int)StateIDs::ATTACKING_STATE)
        {
            return ActionIDs::ACTION_HERO_MAGE_NORMAL_ATK1;
        }
        else if (state_id == (int)StateIDs::BEING_ATTACKED_STATE)
        {
            return ActionIDs::ACTION_HERO_MAGE_HURT1;
        }
        else if (state_id == (int)StateIDs::DEFENDING_STATE)
        {
            return ActionIDs::ACTION_HERO_MAGE_DEFEND;
        }
        break;
    default:
        break;
    }

    return ActionIDs::ACTION_HERO_KNIGHT_IDLE;
}

ActionIDs DataManager::getIdleActionID(int actor_type) const
{  
    if (actor_type == ActorTypes::ACTOR_HERO_KNIGHT)
    {
        return ActionIDs::ACTION_HERO_KNIGHT_IDLE;
    }
    else if (actor_type == ActorTypes::ACTOR_HERO_ARCHER)
    {
        return ActionIDs::ACTION_HERO_ARCHER_IDLE;
    }
    else if (actor_type == ActorTypes::ACTOR_HERO_MAGE)
    {
        return ActionIDs::ACTION_HERO_MAGE_IDLE;
    }

    return ActionIDs::ACTION_HERO_KNIGHT_IDLE;
}

ActionIDs DataManager::getNearingActionID(int actor_type) const
{
    if (actor_type == ActorTypes::ACTOR_HERO_KNIGHT)
    {
        return ActionIDs::ACTION_HERO_KNIGHT_WALK;
    }
    else if (actor_type == ActorTypes::ACTOR_HERO_ARCHER)
    {
        return ActionIDs::ACTION_HERO_ARCHER_WALK;
    }
    else if (actor_type == ActorTypes::ACTOR_HERO_MAGE)
    {
        return ActionIDs::ACTION_HERO_MAGE_WALK;
    }

    return ActionIDs::ACTION_HERO_KNIGHT_WALK;
}

ActionIDs DataManager::getDeadActionID(int actor_type) const
{
    if (actor_type == ActorTypes::ACTOR_HERO_KNIGHT)
    {
        return ActionIDs::ACTION_HERO_KNIGHT_DEAD;
    }
    else if (actor_type == ActorTypes::ACTOR_HERO_ARCHER)
    {
        return ActionIDs::ACTION_HERO_ARCHER_DEAD;
    }
    else if (actor_type == ActorTypes::ACTOR_HERO_MAGE)
    {
        return ActionIDs::ACTION_HERO_MAGE_DEAD;
    }

    return ActionIDs::ACTION_HERO_KNIGHT_DEAD;
}

gamer::cfg::ActionIDs DataManager::getDefendingActionID(int actor_type) const
{
    switch (actor_type)
    {
    case ActorTypes::ACTOR_HERO_KNIGHT:
        return ActionIDs::ACTION_HERO_KNIGHT_DEFEND;
    case ActorTypes::ACTOR_HERO_ARCHER:
        return ActionIDs::ACTION_HERO_ARCHER_DEFEND;
    case ActorTypes::ACTOR_HERO_MAGE:
        return ActionIDs::ACTION_HERO_MAGE_DEFEND;
    default:
        break;
    }

    return ActionIDs::ACTION_HERO_KNIGHT_DEFEND;
}

ActionIDs DataManager::getNormalAttackActionID(int actor_type) const
{
    switch (actor_type)
    {
    case ActorTypes::ACTOR_HERO_KNIGHT:
        return ActionIDs::ACTION_HERO_KNIGHT_NORMAL_ATK1;
    case ActorTypes::ACTOR_HERO_ARCHER:
        return ActionIDs::ACTION_HERO_ARCHER_NORMAL_ATK1;
    case ActorTypes::ACTOR_HERO_MAGE:
        return ActionIDs::ACTION_HERO_MAGE_NORMAL_ATK1;
    default:
        break;
    }

    return ActionIDs::ACTION_HERO_KNIGHT_NORMAL_ATK1;
}

ActionIDs DataManager::getSpecialAttackActionID(int actor_type) const
{
    switch (actor_type)
    {
    case ActorTypes::ACTOR_HERO_KNIGHT:
        return ActionIDs::ACTION_HERO_KNIGHT_SPECIAL_ATK1;
    case ActorTypes::ACTOR_HERO_ARCHER:
        return ActionIDs::ACTION_HERO_ARCHER_SPECIAL_ATK1;
    case ActorTypes::ACTOR_HERO_MAGE:
        return ActionIDs::ACTION_HERO_MAGE_SPECIAL_ATK1;
    default:
        break;
    }

    return ActionIDs::ACTION_HERO_KNIGHT_NORMAL_ATK1;
}

ActionIDs DataManager::getNormalHurtActionID(int actor_type) const
{
    switch (actor_type)
    {
    case ActorTypes::ACTOR_HERO_KNIGHT:
        return ActionIDs::ACTION_HERO_KNIGHT_HURT1;
    case ActorTypes::ACTOR_HERO_ARCHER:
        return ActionIDs::ACTION_HERO_ARCHER_HURT1;
    case ActorTypes::ACTOR_HERO_MAGE:
        return ActionIDs::ACTION_HERO_MAGE_HURT1;
    default:
        break;
    }

    return ActionIDs::ACTION_HERO_KNIGHT_HURT1;
}

const std::string& DataManager::getNormalAttackAudio(int actor_type) const
{
    switch (actor_type)
    {
    case ActorTypes::ACTOR_HERO_KNIGHT:
        if (audio_cfg_.audio_size() > AudioIDs::AUDIO_HERO_KNIGHT_NORMAL_ATK1)
            return audio_cfg_.audio(AudioIDs::AUDIO_HERO_KNIGHT_NORMAL_ATK1).file();
    case ActorTypes::ACTOR_HERO_ARCHER:
        if (audio_cfg_.audio_size() > AudioIDs::AUDIO_HERO_ARCHER_NORMAL_ATK1)
            return audio_cfg_.audio(AudioIDs::AUDIO_HERO_ARCHER_NORMAL_ATK1).file();
    case ActorTypes::ACTOR_HERO_MAGE:
        if (audio_cfg_.audio_size() > AudioIDs::AUDIO_HERO_MAGE_NORMAL_ATK1)
            return audio_cfg_.audio(AudioIDs::AUDIO_HERO_MAGE_NORMAL_ATK1).file();
    default:
        break;
    }

    return audio_cfg_.audio(0).file();
}

const std::string& DataManager::getSpecialAttackAudio(int actor_type) const
{
    switch (actor_type)
    {
    case ActorTypes::ACTOR_HERO_KNIGHT:
        if (audio_cfg_.audio_size() > AudioIDs::AUDIO_HERO_KNIGHT_SPECIAL_ATK1)
            return audio_cfg_.audio(AudioIDs::AUDIO_HERO_KNIGHT_SPECIAL_ATK1).file();
    case ActorTypes::ACTOR_HERO_ARCHER:
        if (audio_cfg_.audio_size() > AudioIDs::AUDIO_HERO_ARCHER_NORMAL_ATK1)
            return audio_cfg_.audio(AudioIDs::AUDIO_HERO_ARCHER_NORMAL_ATK1).file();
    case ActorTypes::ACTOR_HERO_MAGE:
        if (audio_cfg_.audio_size() > AudioIDs::AUDIO_HERO_MAGE_SPECIAL_ATK1)
            return audio_cfg_.audio(AudioIDs::AUDIO_HERO_MAGE_SPECIAL_ATK1).file();
    default:
        break;
    }

    return audio_cfg_.audio(0).file();
}

const std::string& DataManager::getNormalHurtAudio(int actor_type) const
{
    switch (actor_type)
    {
    case ActorTypes::ACTOR_HERO_KNIGHT:
        if (audio_cfg_.audio_size() > AudioIDs::AUDIO_HERO_KNIGHT_HURT1)
            return audio_cfg_.audio(AudioIDs::AUDIO_HERO_KNIGHT_HURT1).file();
    case ActorTypes::ACTOR_HERO_ARCHER:
        if (audio_cfg_.audio_size() > AudioIDs::AUDIO_HERO_ARCHER_HURT1)
            return audio_cfg_.audio(AudioIDs::AUDIO_HERO_ARCHER_HURT1).file();
    case ActorTypes::ACTOR_HERO_MAGE:
        if (audio_cfg_.audio_size() > AudioIDs::AUDIO_HERO_MAGE_HURT1)
            return audio_cfg_.audio(AudioIDs::AUDIO_HERO_MAGE_HURT1).file();
    default:
        break;
    }

    return audio_cfg_.audio(0).file();
}

} // namespace gamer 