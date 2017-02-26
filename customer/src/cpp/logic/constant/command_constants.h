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
    CMD_ID_INVALID               = 0,
    CMD_ID_CREATE_SCENE,
    CMD_ID_CHANGE_SCENE,
    CMD_ID_CREATE_ACTORS,
    CMD_ID_INIT_CAMERA,

    // attack cmd
    CMD_ID_NORMAL_ATTACK         = 1000,
    CMD_ID_NORMAL_ATTACK2,
    CMD_ID_SPECAIL_ATTACK,
    CMD_ID_SPECAIL_ATTACK2,

    CMD_ID_PLAY_ACTION           = 2000,
    CMD_ID_PLAY_IDLE_ACTION      = 2001,
    CMD_ID_PLAY_WALK_ACTION      = 2002,
    CMD_ID_PLAY_DEAD_ACTION      = 2003,

    CMD_ID_DRAW_PATH,
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_COMMAND_DEFINE_H_