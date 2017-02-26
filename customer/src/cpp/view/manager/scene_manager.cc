/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  scene_manager.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-01-03
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "scene_manager.h"

#include <cassert>

#include "command.h"
#include "command_constants.h"
#include "command_listener.h"
#include "command_manager.h"
#include "event.h"
#include "gaming_scene.h"
#include "gaming_hud.h"
#include "scene_constants.h"
#include "space_partition_test_scene.h" // test
#include "macros.h"
#include "test/ui_test.h"

namespace gamer
{

SceneManager::SceneManager() 
    :cur_scene_(nullptr)
{
   
}

SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::getInstance()
{
    static SceneManager* scene_manager = nullptr;
    if (nullptr == scene_manager)
    {
        scene_manager = new SceneManager();
        if ( !scene_manager->initListeners() )
        {
            SAFE_DELETE(scene_manager); 
        }
    }

    return scene_manager;
}

bool SceneManager::initListeners()
{
    auto listener = gamer::CommandListener::create(
        CommandIDs::CMD_ID_CREATE_SCENE, 
        std::bind(&SceneManager::onCommandCreateScene, this, std::placeholders::_1),
        "SceneManager::onCommandCreateScene", 
        1);
    CommandManager::getInstance()->addCmdListener(listener);

    return true;
}

cocos2d::Scene* SceneManager::getRunningScene()
{
    auto scene = cocos2d::Director::getInstance()->getRunningScene();
    if (nullptr != scene)
        return scene;

    return cur_scene_;
}

cocos2d::Scene* SceneManager::getCurrentScene()
{
    auto scene = cocos2d::Director::getInstance()->getRunningScene();
    if (nullptr != scene)
        return scene;

    return cur_scene_;
}

int SceneManager::getCurrentSceneID()
{
    auto scene = cocos2d::Director::getInstance()->getRunningScene();
    if (nullptr != scene)
        return scene->get_scene_id();

    if (nullptr != cur_scene_)
        return cur_scene_->get_scene_id();

    return 0;
}

cocos2d::Scene* SceneManager::createGamingScene()
{
    auto scene = GamingScene::createScene();
    
    scene->set_scene_id(SceneIDs::SCENE_ID_GAME_MAIN_SCENE);
    //set_cur_scene(scene);
    
    return scene;
}

bool SceneManager::init()
{
    return true;
}

cocos2d::Layer* SceneManager::createGamingHUD()
{
    return GamingHUD::create();
}
    
graph::Size SceneManager::getNumOfSpaceBox() const
{
    auto layer = getRootLayerOfGamingScene();
    if (nullptr != layer)
    {
        return layer->num_space_box_;
    }
    
    return graph::Size();
}

graph::Size SceneManager::getSizeOfSpaceBox() const
{
    auto layer = getRootLayerOfGamingScene();
    if (nullptr != layer)
    {
        return layer->size_space_box_;
    }
    
    return graph::Size();
}
    
cocos2d::Vec3 SceneManager::getSpaceOriginOfScene() const
{
    auto layer = getRootLayerOfGamingScene();
    if (nullptr != layer)
    {
        return layer->space_ori_;
    }
    
    return cocos2d::Vec3();
}
    
graph::Cell SceneManager::getCellOfScene() const
{
    auto layer = getRootLayerOfGamingScene();
    if (nullptr != layer)
    {
        return layer->cell_;
    }
    
    return graph::Cell();
}

graph::Size SceneManager::getCellNumOfScene() const
{
    auto layer = getRootLayerOfGamingScene();
    if (nullptr != layer)
    {
        return layer->cells_num_;
    }
    
    return graph::Size();
}

cocos2d::DrawNode3D* SceneManager::draw_node_3d() const
{
    auto layer = getRootLayerOfGamingScene();
    if (nullptr != layer)
    {
        return layer->draw_node_;
    }
    
    return nullptr;
}
  
graph::SpacePartition3D* SceneManager::getSpacePartition() const
{
    auto layer = getRootLayerOfGamingScene();
    if (nullptr != layer)
    {
        return layer->space_partition_;
    }
    
    return nullptr;
}
    
//void SceneManager::onCommandCreateScene(gamer::Event* event)
void SceneManager::onCommandCreateScene(gamer::Command* cmd)
{
    cocos2d::log("[SceneManager::onCommandCreateScene] begin");
    
    // create gaming scene and run it
    //if (nullptr == event->user_data())
    //    return;

    //auto scene = (cocos2d::Scene*)event->user_data();

    auto scene = createGamingScene();
    if (nullptr == scene)
    {
        cocos2d::log("[SceneManager::onCommandCreateScene] create gaming scene failed!");
        return;
    }

    if (nullptr == cocos2d::Director::getInstance()->getRunningScene())
    {
        cocos2d::Director::getInstance()->runWithScene(scene);
    }
    else
    {
        cocos2d::Director::getInstance()->replaceScene(scene);
    }   

    // test
    //scene = gamer::SpacePartitionTestScene::createScene();
    //cocos2d::Director::getInstance()->replaceScene(scene);
    // end test

    cur_scene_ = scene;

    // create gaming hud and add it to camera
    auto layer_hud = createGamingHUD();

    auto camera = cur_scene_->getDefaultCamera();
    camera->addChild(layer_hud);

    // create ui for test
    //auto ui_test = UITest::create();

    //auto camera = cur_scene_->getDefaultCamera();
    //camera->addChild(ui_test);

    cocos2d::log("[SceneManager::onCommandCreateScene] end");
}

void SceneManager::onCommandReplaceScene(gamer::Event* event)
{
    cocos2d::log("[SceneManager::onCommandReplaceScene] begin");
    cocos2d::log("[SceneManager::onCommandReplaceScene] end");
}

void SceneManager::replaceSceneWithTransitionStyle(cocos2d::Scene* scene, int transition_style, float time)
{
    if (nullptr == scene)
        return;

    switch (transition_style)
    {
    case CROSS_FADE:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionCrossFade::create(time, scene));
        break;

    case FADE:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(time, scene));
        break;

    case FADE_BL:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFadeBL::create(time, scene));
        break;

    case FADE_DOWN:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFadeDown::create(time, scene));
        break;

    case FADE_TR:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFadeTR::create(time, scene));
        break;

    case FADE_UP:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFadeUp::create(time, scene));
        break;

    case FLIP_ANGULAR:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFlipAngular::create(time, scene));
        break;

    case FLIP_X:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFlipX::create(time, scene));
        break;

    case FLIP_Y:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFlipY::create(time, scene));
        break;

    case JUMP_ZOOM:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionJumpZoom::create(time, scene));
        break;

    case MOVE_IN_B:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionMoveInB::create(time, scene));
        break;

    case MOVE_IN_L:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionMoveInL::create(time, scene));
        break;

    case MOVE_IN_R:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionMoveInR::create(time, scene));
        break;

    case MOVE_IN_T:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionMoveInT::create(time, scene));
        break;

    case PAGE_TURN:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionPageTurn::create(time, scene,true));
        break;

    case PROGRESS:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionProgress::create(time, scene));
        break;

    case PROGRESS_HORIZONTAL:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionProgressHorizontal::create(time, scene));
        break;

    case PROGRESS_INOUT:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionProgressInOut::create(time, scene));
        break;

    case PROGRESS_OUTIN:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionProgressOutIn::create(time, scene));
        break;

    case PROGRESS_RADIAL_CCW:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionProgressRadialCCW::create(time, scene));
        break;

    case PROGRESS_RADIAL_CW:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionProgressRadialCW::create(time, scene));
        break;

    case PROGRESS_VERTICAL:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionProgressVertical::create(time, scene));
        break;

    case ROTO_ZOOM:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionRotoZoom::create(time, scene));
        break;

    case SHRINK_GROW:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionShrinkGrow::create(time, scene));
        break;

    case SLIDE_IN_B:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionSlideInB::create(time, scene));
        break;

    case SLIDE_IN_L:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionSlideInL::create(time, scene));
        break;

    case SLIDE_IN_R:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionSlideInR::create(time, scene));
        break;

    case SLIDE_IN_T:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionSlideInT::create(time, scene));
        break;

    case SPLIT_COLS:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionSplitCols::create(time, scene));
        break;

    case SPLIT_ROWS:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionSplitRows::create(time, scene));
        break;	

    case TURN_OFF_TILES:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionTurnOffTiles::create(time, scene));
        break;	

    case ZOOM_FLIP_ANGULAR:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionZoomFlipAngular::create(time, scene));
        break;

    case ZOOM_FLIP_X:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionZoomFlipX::create(time, scene));
        break;

    case ZOOM_FLIP_Y:
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionZoomFlipY::create(time, scene));
        break;

    default:
        cocos2d::Director::getInstance()->replaceScene(scene);
        break;
    }
}

gamer::GamingScene* SceneManager::getRootLayerOfGamingScene() const
{
    if (nullptr != cur_scene_)
    {
        auto layer = cur_scene_->getChildByTag(LayerTags::GAMING_SCENE_ROOT_LAYER);
        if (nullptr != layer)
        {
            return static_cast<GamingScene*>(layer);
        }
    }
    
    return nullptr;
}

} // namespace gamer