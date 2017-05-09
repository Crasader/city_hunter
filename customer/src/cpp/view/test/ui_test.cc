/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  ui_test.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-01-17
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "ui_test.h"

#include "util_test.h"

namespace gamer 
{

bool UITest::init()
{
    if ( !cocos2d::Layer::init() )
    {
        return false;
    }

    initVars();

    initPosition();

    initButtons();

    return true;
}

void UITest::initPosition()
{
    auto win_size = cocos2d::Director::getInstance()->getWinSize();

    float x = -win_size.width / 2;
    float y = -win_size.height / 2;
    float z = -cocos2d::Director::getInstance()->getZEye();

    this->setPosition3D(cocos2d::Vec3(x, y, z));
}

void UITest::initButtons()
{
    // btn draw space
    auto btn_draw_space = cocos2d::ui::Button::create("icon/i_80x80_blue.png");
    this->addChild(btn_draw_space);

    auto visible_ori = cocos2d::Director::getInstance()->getVisibleOrigin();

    float x = ui_top_left_.x + btn_draw_space->getContentSize().width / 2;
    float y = ui_top_left_.y - btn_draw_space->getContentSize().height / 2;    
    btn_draw_space->setPosition(cocos2d::Vec2(x, y));

    btn_draw_space->setTitleText("DrawSpace");
    btn_draw_space->setTitleFontSize(15);

    btn_draw_space->addTouchEventListener(CC_CALLBACK_2(UITest::onBtnDrawSpaceTouch, this));

    // btn close
    auto btn_close = cocos2d::ui::Button::create("icon/i_50x50_close.png");
    this->addChild(btn_close);

    x = ui_top_right_.x + btn_close->getContentSize().width / 2;
    y = ui_top_right_.y + btn_close->getContentSize().height / 2;
    btn_close->setPosition(cocos2d::Vec2(x, y));

    btn_close->addTouchEventListener(CC_CALLBACK_2(UITest::onBtnCloseTouch, this));
}

void UITest::initVars()
{
    auto visible_size = cocos2d::Director::getInstance()->getVisibleSize();
    auto visible_ori = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    ui_top_left_.x = visible_ori.x + 150;
    ui_top_left_.y = visible_ori.y + visible_size.height - 150;

    ui_top_right_.x = visible_ori.x + visible_size.width - 150;
    ui_top_right_.y = visible_ori.y + visible_size.height - 150;
}

void UITest::onBtnCloseTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    this->removeFromParentAndCleanup(true);
}

void UITest::onBtnDrawSpaceTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    util_test::drawSpace();
}

} // namespace gamer 