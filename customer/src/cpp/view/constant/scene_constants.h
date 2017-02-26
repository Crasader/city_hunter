/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  scene_constants.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-01-16
  @ description:  define constants for scene.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_SCENE_CONSTANTS_H_
#define CITY_HUNTER_SRC_SCENE_CONSTANTS_H_

namespace gamer
{

enum SceneIDs
{
    SCENE_ID_INVALID            = 0,
    SCENE_ID_GAME_MAIN_SCENE    = 1,
    SCENE_ID_MAX                = 8888
};

enum LayerTags
{
    GAMING_SCENE_ROOT_LAYER
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_SCENE_CONSTANTS_H_