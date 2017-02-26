/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  gaming_hud.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-11-01
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "gaming_hud.h"

#include "command_constants.h"
#include "command_manager.h"
#include "path_finder.h"
#include "scene_manager.h"
#include "test/ui_test.h"
#include "util/utils_graph.h"

namespace gamer 
{

bool GamingHUD::init()
{
    if ( !cocos2d::Layer::init() )
    {
        return false;
    }

    auto win_size = cocos2d::Director::getInstance()->getWinSize();
    auto origin   = cocos2d::Director::getInstance()->getVisibleOrigin();

    //this->setPositionZ(-cocos2d::Director::getInstance()->getZEye() / 2);
    //this->setScale(0.25f);
    //uiLayer:ignoreAnchorVec2ForPosition(false)
    
    this->setPosition3D(cocos2d::Vec3(-win_size.width / 2, -win_size.height / 2, -cocos2d::Director::getInstance()->getZEye()));
    //this->ignoreAnchorVec2ForPosition(false);

    this->setGlobalZOrder(3000);

    initButtons();

    return true;
}

void GamingHUD::initButtons()
{
    // btn source 
    auto btn_source = cocos2d::ui::Button::create("icon/rectangle_80x80_source.png");
    this->addChild(btn_source);

    auto win_size = cocos2d::Director::getInstance()->getWinSize();
    auto origin   = cocos2d::Director::getInstance()->getVisibleOrigin();

    float x = origin.x + win_size.width - btn_source->getContentSize().width / 2;
    float y = origin.y + btn_source->getContentSize().height / 2;
    btn_source->setPosition(cocos2d::Vec2(x, y));

    btn_source->addTouchEventListener(CC_CALLBACK_2(GamingHUD::onBtnSourceTouch, this));

    // btn target 
    auto btn_target = cocos2d::ui::Button::create("icon/rectangle_80x80_target.png");
    this->addChild(btn_target);

    x = origin.x + win_size.width - btn_source->getContentSize().width / 2 - btn_source->getContentSize().width - 10;
    y = origin.y + btn_target->getContentSize().height / 2;
    btn_target->setPosition(cocos2d::Vec2(x, y));

    btn_target->addTouchEventListener(CC_CALLBACK_2(GamingHUD::onBtnTargetTouch, this));

    // btn obstacle
    auto btn_obstacle = cocos2d::ui::Button::create("icon/rectangle_80x80_obstacle.png");
    this->addChild(btn_obstacle);

    x = origin.x + win_size.width - btn_obstacle->getContentSize().width / 2 - 2 * btn_source->getContentSize().width - 20;
    y = origin.y + btn_obstacle->getContentSize().height / 2;
    btn_obstacle->setPosition(cocos2d::Vec2(x, y));

    btn_obstacle->addTouchEventListener(CC_CALLBACK_2(GamingHUD::onBtnObstacleTouch, this));

    // btn astar
    auto btn_astar = cocos2d::ui::Button::create("icon/rectangle_80x80_blue.png");
    this->addChild(btn_astar);

    x = origin.x + btn_astar->getContentSize().width / 2;
    y = origin.y + btn_astar->getContentSize().height / 2;
    btn_astar->setPosition(cocos2d::Vec2(x, y));

    btn_astar->setTitleText("A*");
    btn_astar->setTitleFontSize(30);

    btn_astar->addTouchEventListener(CC_CALLBACK_2(GamingHUD::onBtnAStarTouch, this));

    // btn ui test
    auto btn_ui_test = cocos2d::ui::Button::create("icon/rectangle_80x80_blue.png");
    this->addChild(btn_ui_test);

    x = origin.x + win_size.width - btn_ui_test->getContentSize().width / 2;
    y = origin.y + btn_ui_test->getContentSize().height * 1.5;
    btn_ui_test->setPosition(cocos2d::Vec2(x, y));

    btn_ui_test->setTitleText("tests");
    btn_ui_test->setTitleFontSize(15);

    btn_ui_test->addTouchEventListener(CC_CALLBACK_2(GamingHUD::onBtnUITestTouch, this));
}

void GamingHUD::onBtnSourceTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    cocos2d::log("[GamingHUD::onBtnSourceTouch]");
    if (cocos2d::ui::Widget::TouchEventType::ENDED == type)
    {
        touched_btn_type_ = TouchedButtonTypes::BTN_SOURCE;
    }    
}

void GamingHUD::onBtnTargetTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    cocos2d::log("[GamingHUD::onBtnTargetTouch]");
    if (cocos2d::ui::Widget::TouchEventType::ENDED == type)
    {
        touched_btn_type_ = TouchedButtonTypes::BTN_TARGET;
    } 
}

void GamingHUD::onBtnObstacleTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    cocos2d::log("[GamingHUD::onBtnObstacleTouch]");
    if (cocos2d::ui::Widget::TouchEventType::ENDED == type)
    {
        touched_btn_type_ = TouchedButtonTypes::BTN_OBSTACLE;

        int obstacle = utils_graph::getNodeIndexByPos(cocos2d::Vec3(0, 0, 0));
        auto graph = PathFinder::getInstance()->graph();
        graph->getNode(obstacle).set_enabled(false);
    } 
}

void GamingHUD::onBtnAStarTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    cocos2d::log("[GamingHUD::onBtnAStarTouch]");
    if (cocos2d::ui::Widget::TouchEventType::ENDED == type)
    {
        //drawPathOfAStarAlgorithms();
        CommandManager::getInstance()->sendCmd(
            CommandIDs::CMD_ID_DRAW_PATH, nullptr);
    } 
}

void GamingHUD::onBtnUITestTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    if (cocos2d::ui::Widget::TouchEventType::ENDED == type)
    {
        auto cur_scene = SceneManager::getInstance()->getRunningScene();
        if (nullptr == cur_scene)
            return;

        auto ui_test = UITest::create();

        auto camera = cur_scene->getDefaultCamera();
        camera->addChild(ui_test);
    }
}

} // namespace gamer