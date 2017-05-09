/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  action_command.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-12-06
  @ description:  actor action command.
  @ others:  
  @ history: 
    1.date:
      author:
      modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_ACTION_COMMAND_H_
#define CITY_HUNTER_SRC_ACTION_COMMAND_H_

#include <string>
#include "command.h"

namespace gamer 
{

struct ActionParam
{
    std::string name;
    bool loop;
};

template<typename Actor>
class ActionCommand : public Command
{
public:
    ActionCommand() 
        :attacker_(nullptr) 
        ,target_(nullptr)
    {
    }

    ActionCommand(int cmd_id) 
        :Command(cmd_id) 
        ,attacker_(nullptr) 
        ,target_(nullptr)
    {
    }

    ~ActionCommand() {}

    inline void set_attacker(Actor* actor) { attacker_ = actor; }

    inline Actor* attacker() const { return attacker_; }

    inline void set_target(Actor* actor) { target_ = actor; }

    inline Actor* target() const { return target_; }

private:
    Actor* attacker_;
    Actor* target_;

    ActionParam attacker_action_;
    ActionParam target_action_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_ACTION_COMMAND_H_