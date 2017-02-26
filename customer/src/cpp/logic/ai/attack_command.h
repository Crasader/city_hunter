/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  attack_command.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-04-02
  @ description:  actor attack command.
  @ others:  
  @ history: 
    1.date:
      author:
      modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_ATTACK_COMMAND_H_
#define CITY_HUNTER_SRC_ATTACK_COMMAND_H_

#include <string>
#include "command.h"

namespace gamer 
{

template<typename Actor>
class AttackCommand : public Command
{
public:
    AttackCommand() {}

    AttackCommand(int cmd_id) : Command(cmd_id) {}

    ~AttackCommand() {}

    inline void set_attacker(Actor* actor) { attacker_ = actor; }

    inline Actor* attacker() const { return attacker_; }

    inline void set_target(Actor* actor) { target_ = actor; }

    inline Actor* target() const { return target_; }

    inline void set_attack_action(const std::string& action) { att_action_ = action; }

    inline const std::string& attack_action() const { return att_action_; }

private:
    Actor* attacker_;
    Actor* target_;

    std::string att_action_; 
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_ATTACK_COMMAND_H_