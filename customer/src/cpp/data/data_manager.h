/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  data_manager.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-11-09
  @ description:  data manager, provider.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_DATA_MANAGER_H_
#define CITY_HUNTER_SRC_DATA_MANAGER_H_

#include <string>
#include "command_constants.h"
#include "actor_cfg.pb.h"

namespace gamer
{

class DataManager
{
public:
    ~DataManager();

    static DataManager* getInstance();

    bool init();

    inline const gamer::ActorCfg& actor_cfg() const { return actor_cfg_; }

    inline const std::string& idle_action() const
    {
        return actor_cfg_.common_action().idle();
    }

    inline const std::string& walk_action() const
    {
        return actor_cfg_.common_action().walk();
    }

    inline const std::string& dead_action() const
    {
       return actor_cfg_.common_action().dead();
    }

    inline const std::string& attack_action(int actor_id, int acttack_cmd) const 
    {
        auto model_idx  = model_index(actor_cfg_, actor_id);
        auto action_index = acttack_cmd % CommandIDs::CMD_ID_NORMAL_ATTACK;
        return actor_cfg_.actor_model(model_idx).action(action_index).name();
    }

    inline const std::string& attacked_action(int actor_id, int acttack_cmd) const
    {
        auto model_idx  = model_index(actor_cfg_, actor_id);
        auto action_index = acttack_cmd % CommandIDs::CMD_ID_NORMAL_ATTACK;
        return actor_cfg_.actor_model(model_idx).action(7).name(); // TODO : 7
    }

    inline const std::string& attack_audio(int actor_id, int acttack_cmd) const 
    {
        auto model_idx  = model_index(actor_cfg_, actor_id);
        if (CommandIDs::CMD_ID_NORMAL_ATTACK2 == acttack_cmd)
        {
            return actor_cfg_.actor_audio(model_idx).normal_atk2();
        }
        return actor_cfg_.actor_audio(model_idx).normal_atk1();
    }

    inline const std::string& attacked_audio(int actor_id, int acttack_cmd) const 
    {
        auto model_idx  = model_index(actor_cfg_, actor_id);
        if (CommandIDs::CMD_ID_SPECAIL_ATTACK == acttack_cmd ||
            CommandIDs::CMD_ID_SPECAIL_ATTACK2 == acttack_cmd)
        {
            return actor_cfg_.actor_audio(model_idx).special_atk_shout();
        }
        return actor_cfg_.actor_audio(model_idx).normal_atk_shout();
    }

private:
    DataManager();    
    
    inline int model_index(const ActorCfg& actor_cfg, int actor_id) const
    {
        return actor_id % actor_cfg.actor_model(0).id();
    }

    std::string dir_cfg_;
    std::string actor_cfg_path_;    
    gamer::ActorCfg actor_cfg_;
    bool is_init_ok_;
};

} // namespace gamer 

#endif // CITY_HUNTER_SRC_DATA_MANAGER_H_