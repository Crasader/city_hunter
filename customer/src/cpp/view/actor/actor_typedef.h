/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  actor_typedef.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-07
  @ description:  actor typedef.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_ACTOR_TYPEDEF_H_
#define CITY_HUNTER_SRC_ACTOR_TYPEDEF_H_

//#include "cocos/3d/CCSprite3D.h"
//#include "actor.h"

namespace cocos2d
{
    
class Sprite3D;

}

namespace gamer
{
    
template<typename Entity> class Actor;
    
typedef Actor<cocos2d::Sprite3D> ActorType;
    
} // CITY_HUNTER_SRC_ACTOR_TYPEDEF_H_

#endif