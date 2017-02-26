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
        :initiator_(nullptr) 
        ,acceptor_(nullptr)
    {
    }

    ActionCommand(int cmd_id) 
        :Command(cmd_id) 
        ,initiator_(nullptr) 
        ,acceptor_(nullptr)
    {
    }

    ~ActionCommand() {}

    inline void set_initiator(Actor* actor) { initiator_ = actor; }

    inline Actor* initiator() const { return initiator_; }

    inline void set_acceptor(Actor* actor) { acceptor_ = actor; }

    inline Actor* acceptor() const { return acceptor_; }

private:
    Actor* initiator_;
    Actor* acceptor_;

    ActionParam initiator_action_;
    ActionParam acceptor_action_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_ACTION_COMMAND_H_