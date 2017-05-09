/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  command_constants.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-01-18
  @ description:  define all commands id here.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_COMMAND_DEFINE_H_
#define CITY_HUNTER_SRC_COMMAND_DEFINE_H_

namespace gamer
{

enum CommandIDs 
{
    CMD_INVALID               = 0,
    CMD_CREATE_SCENE,
    CMD_CHANGE_SCENE,
    CMD_CREATE_ACTORS,
    CMD_INIT_CAMERA,

    // attack cmd
    CMD_ATTACK                = 999,
    CMD_NORMAL_ATTACK,         
    CMD_NORMAL_ATTACK2,
    CMD_SPECAIL_ATTACK,
    CMD_SPECAIL_ATTACK2,

    CMD_PLAY_ACTION           = 2000,
    CMD_PLAY_IDLE_ACTION,
    CMD_PLAY_WALK_ACTION,
    CMD_PLAY_DEAD_ACTION,

    CMD_DRAW_PATH, // test
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_COMMAND_DEFINE_H_