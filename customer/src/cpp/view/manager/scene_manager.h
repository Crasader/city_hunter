/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  scene_manager.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-01-03
  @ description:  offer function to manager scene, such as manager scene creation
                  scene replace, etc.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef  CITY_HUNTER_SRC_SCENE_MANAGER_H_
#define  CITY_HUNTER_SRC_SCENE_MANAGER_H_

#include "cocos2d.h"

//#include "typedef.h"
#include "graph_typedef.h"

namespace cocos2d 
{

class DrawNode3D;
    
}

namespace gamer 
{

class Command;
class Event;
class GamingScene;
    
class SceneManager 
{
public:
    enum TransitionStyle
    {
        NONE,
        CROSS_FADE,
        FADE,
        FADE_BL,
        FADE_DOWN,
        FADE_TR,
        FADE_UP,
        FLIP_ANGULAR,
        FLIP_X,
        FLIP_Y,
        JUMP_ZOOM,
        MOVE_IN_B,
        MOVE_IN_L,
        MOVE_IN_R,
        MOVE_IN_T,
        PAGE_TURN,
        PROGRESS,
        PROGRESS_HORIZONTAL,
        PROGRESS_INOUT,
        PROGRESS_OUTIN,
        PROGRESS_RADIAL_CCW,
        PROGRESS_RADIAL_CW,
        PROGRESS_VERTICAL,
        ROTO_ZOOM,
        SHRINK_GROW,
        SLIDE_IN_B,
        SLIDE_IN_L,
        SLIDE_IN_R,
        SLIDE_IN_T,
        SPLIT_COLS,
        SPLIT_ROWS,
        TURN_OFF_TILES,
        ZOOM_FLIP_ANGULAR,
        ZOOM_FLIP_X,
        ZOOM_FLIP_Y
    };

	~SceneManager();

	static SceneManager* getInstance();

    bool init();

	cocos2d::Scene* getRunningScene();
	
    cocos2d::Scene* getCurrentScene();

    inline cocos2d::Scene* cur_scene() const
    {
        return cur_scene_;
    }

    inline void set_cur_scene(cocos2d::Scene* scene)
    {
        if (nullptr != scene)
        {
            cur_scene_ = scene;
        }
    }

    int getCurrentSceneID();	

    graph::Size getNumOfSpaceBox() const;

    graph::Size getSizeOfSpaceBox() const;

    cocos2d::Vec3 getSpaceOriginOfScene() const;
    
    graph::Cell getCellOfScene() const;
    
    graph::Size getCellNumOfScene() const;
    
    cocos2d::DrawNode3D* draw_node_3d() const;
    
    graph::SpacePartition3D* getSpacePartition() const;
    
private:
    SceneManager();

    bool initListeners();

    //void onCommandCreateScene(gamer::Event* event);
    void onCommandCreateScene(gamer::Command* cmd);

    void onCommandReplaceScene(gamer::Event* event);

    void replaceSceneWithTransitionStyle(cocos2d::Scene* scene, int transition_style, float time);
    
    gamer::GamingScene* getRootLayerOfGamingScene() const;
    
    cocos2d::Scene* createGamingScene();

    cocos2d::Layer* createGamingHUD();

    cocos2d::Scene* cur_scene_;
};

} // namespace gamer

#endif  // CITY_HUNTER_SRC_SCENE_MANAGER_H_