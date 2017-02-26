/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  event_define.h
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

#ifndef CITY_HUNTER_SRC_EVENT_DEFINE_H_
#define CITY_HUNTER_SRC_EVENT_DEFINE_H_

namespace gamer 
{

//namespace eventname{
//static const char* Hero_Is_Attack =  "Hero_Is_Attack";
//}

enum EventIDs 
{
    INVALID              = 0,
    EVENT_ID_ACTORS_CREATED,
	HERO_UNDER_ATTACK,
	HERO_DEAD,
    EVENT_ID_MAX         = 8888
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_EVENT_DEFINE_H_