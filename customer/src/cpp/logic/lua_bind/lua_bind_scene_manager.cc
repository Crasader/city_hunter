/*
** Lua binding: scene_manager
** Generated automatically by tolua++-1.0.92 on 04/11/15 17:32:16.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_scene_manager_open (lua_State* tolua_S);

#include "scene_manager.h"
#include "cocos2d.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__SceneManager (lua_State* tolua_S)
{
 gamer::SceneManager* self = (gamer::SceneManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"cocos2d::Scene");
 tolua_usertype(tolua_S,"gamer::SceneManager");
}

/* method: delete of class  gamer::SceneManager */
#ifndef TOLUA_DISABLE_tolua_scene_manager_gamer_SceneManager_delete00
static int tolua_scene_manager_gamer_SceneManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::SceneManager* self = (gamer::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  gamer::SceneManager */
#ifndef TOLUA_DISABLE_tolua_scene_manager_gamer_SceneManager_getInstance00
static int tolua_scene_manager_gamer_SceneManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::SceneManager* tolua_ret = (gamer::SceneManager*)  gamer::SceneManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRunningScene of class  gamer::SceneManager */
#ifndef TOLUA_DISABLE_tolua_scene_manager_gamer_SceneManager_getRunningScene00
static int tolua_scene_manager_gamer_SceneManager_getRunningScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::SceneManager* self = (gamer::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRunningScene'", NULL);
#endif
  {
   cocos2d::Scene* tolua_ret = (cocos2d::Scene*)  self->getRunningScene();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cocos2d::Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRunningScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentScene of class  gamer::SceneManager */
#ifndef TOLUA_DISABLE_tolua_scene_manager_gamer_SceneManager_getCurrentScene00
static int tolua_scene_manager_gamer_SceneManager_getCurrentScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::SceneManager* self = (gamer::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentScene'", NULL);
#endif
  {
   cocos2d::Scene* tolua_ret = (cocos2d::Scene*)  self->getCurrentScene();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cocos2d::Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentSceneID of class  gamer::SceneManager */
#ifndef TOLUA_DISABLE_tolua_scene_manager_gamer_SceneManager_getCurrentSceneID00
static int tolua_scene_manager_gamer_SceneManager_getCurrentSceneID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::SceneManager* self = (gamer::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentSceneID'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCurrentSceneID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentSceneID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_scene_manager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"SceneManager","gamer::SceneManager","",tolua_collect_gamer__SceneManager);
   #else
   tolua_cclass(tolua_S,"SceneManager","gamer::SceneManager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"SceneManager");
    tolua_constant(tolua_S,"NONE",gamer::SceneManager::NONE);
    tolua_constant(tolua_S,"CROSS_FADE",gamer::SceneManager::CROSS_FADE);
    tolua_constant(tolua_S,"FADE",gamer::SceneManager::FADE);
    tolua_constant(tolua_S,"FADE_BL",gamer::SceneManager::FADE_BL);
    tolua_constant(tolua_S,"FADE_DOWN",gamer::SceneManager::FADE_DOWN);
    tolua_constant(tolua_S,"FADE_TR",gamer::SceneManager::FADE_TR);
    tolua_constant(tolua_S,"FADE_UP",gamer::SceneManager::FADE_UP);
    tolua_constant(tolua_S,"FLIP_ANGULAR",gamer::SceneManager::FLIP_ANGULAR);
    tolua_constant(tolua_S,"FLIP_X",gamer::SceneManager::FLIP_X);
    tolua_constant(tolua_S,"FLIP_Y",gamer::SceneManager::FLIP_Y);
    tolua_constant(tolua_S,"JUMP_ZOOM",gamer::SceneManager::JUMP_ZOOM);
    tolua_constant(tolua_S,"MOVE_IN_B",gamer::SceneManager::MOVE_IN_B);
    tolua_constant(tolua_S,"MOVE_IN_L",gamer::SceneManager::MOVE_IN_L);
    tolua_constant(tolua_S,"MOVE_IN_R",gamer::SceneManager::MOVE_IN_R);
    tolua_constant(tolua_S,"MOVE_IN_T",gamer::SceneManager::MOVE_IN_T);
    tolua_constant(tolua_S,"PAGE_TURN",gamer::SceneManager::PAGE_TURN);
    tolua_constant(tolua_S,"PROGRESS",gamer::SceneManager::PROGRESS);
    tolua_constant(tolua_S,"PROGRESS_HORIZONTAL",gamer::SceneManager::PROGRESS_HORIZONTAL);
    tolua_constant(tolua_S,"PROGRESS_INOUT",gamer::SceneManager::PROGRESS_INOUT);
    tolua_constant(tolua_S,"PROGRESS_OUTIN",gamer::SceneManager::PROGRESS_OUTIN);
    tolua_constant(tolua_S,"PROGRESS_RADIAL_CCW",gamer::SceneManager::PROGRESS_RADIAL_CCW);
    tolua_constant(tolua_S,"PROGRESS_RADIAL_CW",gamer::SceneManager::PROGRESS_RADIAL_CW);
    tolua_constant(tolua_S,"PROGRESS_VERTICAL",gamer::SceneManager::PROGRESS_VERTICAL);
    tolua_constant(tolua_S,"ROTO_ZOOM",gamer::SceneManager::ROTO_ZOOM);
    tolua_constant(tolua_S,"SHRINK_GROW",gamer::SceneManager::SHRINK_GROW);
    tolua_constant(tolua_S,"SLIDE_IN_B",gamer::SceneManager::SLIDE_IN_B);
    tolua_constant(tolua_S,"SLIDE_IN_L",gamer::SceneManager::SLIDE_IN_L);
    tolua_constant(tolua_S,"SLIDE_IN_R",gamer::SceneManager::SLIDE_IN_R);
    tolua_constant(tolua_S,"SLIDE_IN_T",gamer::SceneManager::SLIDE_IN_T);
    tolua_constant(tolua_S,"SPLIT_COLS",gamer::SceneManager::SPLIT_COLS);
    tolua_constant(tolua_S,"SPLIT_ROWS",gamer::SceneManager::SPLIT_ROWS);
    tolua_constant(tolua_S,"TURN_OFF_TILES",gamer::SceneManager::TURN_OFF_TILES);
    tolua_constant(tolua_S,"ZOOM_FLIP_ANGULAR",gamer::SceneManager::ZOOM_FLIP_ANGULAR);
    tolua_constant(tolua_S,"ZOOM_FLIP_X",gamer::SceneManager::ZOOM_FLIP_X);
    tolua_constant(tolua_S,"ZOOM_FLIP_Y",gamer::SceneManager::ZOOM_FLIP_Y);
    tolua_function(tolua_S,"delete",tolua_scene_manager_gamer_SceneManager_delete00);
    tolua_function(tolua_S,"getInstance",tolua_scene_manager_gamer_SceneManager_getInstance00);
    tolua_function(tolua_S,"getRunningScene",tolua_scene_manager_gamer_SceneManager_getRunningScene00);
    tolua_function(tolua_S,"getCurrentScene",tolua_scene_manager_gamer_SceneManager_getCurrentScene00);
    tolua_function(tolua_S,"getCurrentSceneID",tolua_scene_manager_gamer_SceneManager_getCurrentSceneID00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_scene_manager (lua_State* tolua_S) {
 return tolua_scene_manager_open(tolua_S);
};
#endif

