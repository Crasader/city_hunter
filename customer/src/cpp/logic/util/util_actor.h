/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  util_actor.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2017-04-06
  @ description:  offer some common functions about actor.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_UTIL_ACTOR_H_
#define CITY_HUNTER_SRC_UTIL_ACTOR_H_

#include "cocos2d.h"

namespace gamer
{

namespace util_actor
{

template <typename Actor>
void turnFace2Target(Actor* src, Actor* target)
{
    auto tar_pos = target->getPosition();
    auto self_pos = src->getPosition();
    cocos2d::Vec2 target_pos1 = cocos2d::Vec2(tar_pos.x, -tar_pos.z);
    cocos2d::Vec2 self_pos1 = cocos2d::Vec2(self_pos.x, -self_pos.z);
    cocos2d::Vec2 target_vec = target_pos1 - self_pos1;
    target_vec.normalize();
    float target_angle = atan2f(target_vec.y, target_vec.x);
    float target_degree = CC_RADIANS_TO_DEGREES(target_angle);

    float cur_facing = src->entity()->getRotation3D().y;
    float delta_degree = target_degree - cur_facing;
    delta_degree = (int)delta_degree % 360;
    bool anti_clockwise = (delta_degree - 180) < 0;
    if (anti_clockwise)
    {
        src->entity()->setRotation3D(cocos2d::Vec3(0, target_degree + 90, 0));
    }
    else
    {
        src->entity()->setRotation3D(cocos2d::Vec3(0, -(360 - target_degree) + 90, 0));
    }
}

} // namespace util_actor

} // namespace gamer

#endif // CITY_HUNTER_SRC_UTIL_ACTOR_H_