/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  event_constants.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-01-18
  @ description:  define all events id here.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_EVENT_CONSTANTS_H_
#define CITY_HUNTER_SRC_EVENT_CONSTANTS_H_

namespace gamer 
{

enum EventIDs 
{
    EVENT_INVALID,
    EVENT_ACTORS_CREATED,
	EVENT_HERO_UNDER_ATTACK,
	EVENT_HERO_DEAD,

    // actor state
    EVENT_ACTOR_ENTERED_STATE   = 1000,
    EVENT_ACTOR_UPDATING_STATE
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_EVENT_CONSTANTS_H_