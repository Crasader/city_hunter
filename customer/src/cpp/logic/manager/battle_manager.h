/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  battle_manager.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2017-04-012
  @ description:  battle manager.change state, play action, play audio, etc.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_BATTLE_MANAGER_H_
#define CITY_HUNTER_SRC_BATTLE_MANAGER_H_

#include "actor_typedef.h"

namespace gamer
{

template<typename Entity> class Actor;
class Command;
class Event;

class BattleManager
{
public:
    ~BattleManager();

    static BattleManager* getInstance();

    static void destoryInstance();

    bool init();

    void dealWithNextState(ActorType* actor);

private:
    BattleManager();

    bool initListeners();

    void onCommandReceived(gamer::Command* cmd);

    void onEventReceived(gamer::Event* event);

    void dealWithAttackCommand(gamer::Command* cmd);

    void dealWithActorEnteredState(gamer::Event* event);
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_BATTLE_MANAGER_H_