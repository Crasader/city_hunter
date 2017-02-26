/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  actor_interface.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-08-15
  @ description:  role interface.
  @ others:  
  @ history: 
    1.date:
      author:
      modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_ACTOR_INTERFACE_H_
#define CITY_HUNTER_SRC_ACTOR_INTERFACE_H_

#include <string> 

namespace gamer 
{

class Actor_Interface 
{
public:
    virtual ~Actor_Interface() {}

    virtual void addAction(const std::string& action_name, 
                           const std::string& file, 
                           float from_time, 
                           float duration, float speed) = 0;

    virtual void playAction(const std::string& action_name, bool loop) = 0;

    // direction > 0 mean set the direction to right,
    // direction < 0 mean set the direction to left.
    //virtual void set_direction(float direction) = 0;

    // return value > 0 mean the direction is right,
    // return value < 0 mean the direction is left.
    //virtual float direction() const = 0;

    // toggle direction of role
    //virtual void toggle_direction() = 0;

    // move role to left by increasing positionX
    //virtual void move_to_left(float distance) = 0;

    // move role to left by decreasing positionX
    // void move_to_right(float distance) = 0;

    // set max health point of role
    //virtual void set_max_hp(int hp) = 0;

    // get max health point of role
    //virtual int max_hp() const = 0;

    // set health point of role
    virtual void set_hp(int hp) = 0;

    // get health point of role
    virtual int hp() const = 0;

    // increase health point of role
    //virtual void increase_hp(int hp) = 0;

    // decrease health point of role
    //virtual void decrease_hp(int hp) = 0;

    virtual void set_damage(int damage) = 0; 

    virtual int damage() const = 0;   
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_ACTOR_INTERFACE_H_
