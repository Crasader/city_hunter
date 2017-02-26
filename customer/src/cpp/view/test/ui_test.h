/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  ui_test.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-01-17
  @ description:  ui for testing.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_UI_TEST_H_
#define CITY_HUNTER_SRC_UI_TEST_H_

#include "cocos2d.h"
#include "cocos/editor-support/cocostudio/CocoStudio.h"
#include "cocos/ui/CocosGUI.h"

namespace gamer
{

class UITest : public cocos2d::Layer 
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    //static cocos2d::cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static create()" method manually
    CREATE_FUNC(UITest);

private:
    void initVars();

    void initPosition();

    void initButtons();

    void onBtnDrawSpaceTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void onBtnCloseTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    cocos2d::Vec2 ui_top_left_;
    cocos2d::Vec2 ui_top_right_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_UI_TEST_H_