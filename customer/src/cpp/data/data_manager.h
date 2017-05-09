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

#include "actor_cfg.pb.h"
#include "action_cfg.pb.h"
#include "actor_state_cfg.pb.h"
#include "audio_cfg.pb.h"
#include "command_constants.h"
#include "camera_cfg.pb.h"
#include "map_cfg.pb.h"
#include "model_cfg.pb.h"

namespace gamer
{

class DataManager
{
public:
    ~DataManager();

    static DataManager* getInstance();

    bool init();

    inline const cfg::MapCfg& map_cfg() const { return map_cfg_; }

	inline const cfg::SpaceCfg& space_cfg() const { return map_cfg_.space_cfg(); }
    
    inline const cfg::CameraCfg& camera_cfg() const { return camera_cfg_; }

    inline const cfg::ActorCfg& actor_cfg() const { return actor_cfg_; }	

    inline const cfg::ActorStateCfg& actor_state_cfg() const { return actor_state_cfg_; }

    inline const cfg::ActionCfg& action_cfg() const { return action_cfg_; }

    inline const cfg::AudioCfg& audio_cfg() const { return audio_cfg_; }

    inline const cfg::ModelCfg& model_cfg() const { return model_cfg_; }

    const cfg::Action& getAction(int actor_type, int action_id) const;

    cfg::ActionIDs getEnterActionID(int actor_type, int state_id) const;

    cfg::ActionIDs getIdleActionID(int actor_type) const;

    cfg::ActionIDs getNearingActionID(int actor_type) const;

    cfg::ActionIDs getDeadActionID(int actor_type) const;

    cfg::ActionIDs getDefendingActionID(int actor_type) const;

    cfg::ActionIDs getNormalAttackActionID(int actor_type) const;

    cfg::ActionIDs getSpecialAttackActionID(int actor_type) const;

    cfg::ActionIDs getNormalHurtActionID(int actor_type) const;

    const std::string& getNormalAttackAudio(int actor_type) const;

    const std::string& getSpecialAttackAudio(int actor_type) const;

    const std::string& getNormalHurtAudio(int actor_type) const;

private:
    DataManager();    

    std::string dir_cfg_;  
   
    cfg::MapCfg map_cfg_;
    cfg::CameraCfg camera_cfg_;
    cfg::ActorCfg actor_cfg_;
    cfg::ActorStateCfg actor_state_cfg_;
    cfg::ActionCfg action_cfg_;
    cfg::AudioCfg audio_cfg_;    
    cfg::ModelCfg model_cfg_;    

    bool is_init_ok_;
};

} // namespace gamer 

#endif // CITY_HUNTER_SRC_DATA_MANAGER_H_