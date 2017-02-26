/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  physics_constants.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-03-28
  @ description:  define physics constants.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_PHYSICS_DEFINE_H_
#define CITY_HUNTER_SRC_PHYSICS_DEFINE_H_

namespace gamer 
{

enum PhysicsBodyBitmasks
{
    CATEGORY_HERO			=	0x1,
    CATEGORY_SOLDIDER		=	0x2,
    //eCategory_Bullet		=	0xffff,
    CATEGORY_BULLET		    =	0x4,
    CATEGORY_EDGEBOX		=	0x8,

    COLLISION_HERO			=	0x4,
    COLLISION_SOLDIDER		=	0x4,
    COLLISION_BULLET		=	0x7,
    COLLISION_EDGEBOX		=	0x8,

    CONTACT_TEST_HERO		=	0x4,
    CONTACT_TEST_SOLDIDER	=	0x4,
    CONTACT_TEST_BULLET	    =	0x7fffffff,
    CONTACT_TEST_EDGEBOX	=	0x4
};

enum PhysicsBodyTags
{
    WEAPON = 2012,
    ROLE,
    HERO,
    ENEMY,
    EDGEBOX
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_PHYSICS_DEFINE_H_