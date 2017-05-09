/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  state_constants.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-03-27
  @ description:  define constants for role state.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_STATE_CONSTANTS_H_
#define CITY_HUNTER_SRC_STATE_CONSTANTS_H_

namespace gamer
{

enum StateIDs
{
    INVALID_STATE,
    IDLE_STATE,
    FINDING_TARGET_STATE,
    NEARING_TARGET_STATE,
    ATTACKING_STATE,
    BEING_ATTACKED_STATE,
    DEFENDING_STATE,
    FLEEING_STATE,
    DEAD_STATE
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_STATE_CONSTANTS_H_