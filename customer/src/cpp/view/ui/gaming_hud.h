/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  gaming_hud.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-11-01
  @ description:  gaming hud.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_GAMING_HUD_H_
#define CITY_HUNTER_SRC_GAMING_HUD_H_

#include "cocos2d.h"
#include "cocos/editor-support/cocostudio/CocoStudio.h"
#include "cocos/ui/CocosGUI.h"

namespace gamer
{

class GamingHUD : public cocos2d::Layer 
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    //static cocos2d::cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static create()" method manually
    CREATE_FUNC(GamingHUD);

private:
    enum TouchedButtonTypes
    {
        BTN_UNKNOWN,
        BTN_SOURCE,
        BTN_TARGET,
        BTN_OBSTACLE
    };

    // buttons of source, target, obstacle, astar
    void initButtons();

    void onBtnSourceTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void onBtnTargetTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void onBtnObstacleTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void onBtnAStarTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void onBtnUITestTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    cocos2d::ui::ImageView* img_purple_target_;  // target   
    cocos2d::ui::ImageView* img_red_source_;     // source
    cocos2d::ui::ImageView* img_gray_obstacle_;  // obstacle

    TouchedButtonTypes touched_btn_type_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_GAMING_HUD_H_