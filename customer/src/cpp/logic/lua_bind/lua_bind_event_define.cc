/*
** Lua binding: event_define
** Generated automatically by tolua++-1.0.92 on 03/01/15 20:03:02.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "../tolua_include/tolua++.h"

/* Exported function */
TOLUA_API int  tolua_event_define_open (lua_State* tolua_S);

#include "../event_define.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* Open function */
TOLUA_API int tolua_event_define_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   tolua_constant(tolua_S,"INVALID",gamer::INVALID);
   tolua_constant(tolua_S,"HERO_UNDER_ATTACK",gamer::HERO_UNDER_ATTACK);
   tolua_constant(tolua_S,"HERO_DEAD",gamer::HERO_DEAD);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_event_define (lua_State* tolua_S) {
 return tolua_event_define_open(tolua_S);
};
#endif

