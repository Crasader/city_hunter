/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  actor_manager.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-11-01
  @ description:  manage creation, destroy of actor, etc.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_ACTOR_MANAGER_H_
#define CITY_HUNTER_SRC_ACTOR_MANAGER_H_

#include <map>

#include "actor_typedef.h"

namespace gamer
{
 
class Command;
class Event;

class ActorManager 
{
public:
    ~ActorManager();

    static ActorManager* getInstance();

    bool init();

    inline std::map<int, ActorType*> created_actors() const { return created_actors_; }

private:
    ActorManager();

    bool initListeners();

    //void onCommandCreateActors(gamer::Event* event); 
    void onCommandCreateActors(gamer::Command* cmd); 

    //inline int next_actor_id() { return actor_id_++; }

    std::map<int, ActorType*> created_actors_;

    //int actor_id_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_ACTOR_MANAGER_H_