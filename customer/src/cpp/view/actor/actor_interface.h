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

    virtual void addAction(int action_id, 
                           const std::string& file, 
                           float from_time, 
                           float duration, float speed) = 0;

    virtual void playAction(int action_id, bool loop) = 0;

    virtual void set_actor_type(int actor_type) = 0;

    virtual int actor_type() const = 0;

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
