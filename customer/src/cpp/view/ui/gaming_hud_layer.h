/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  gaming_hud_layer.h
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

#ifndef CITY_HUNTER_SRC_GAMING_HUD_LAYER_H_
#define CITY_HUNTER_SRC_GAMING_HUD_LAYER_H_

#include "cocos2d.h"
#include "cocos/editor-support/cocostudio/CocoStudio.h"
#include "cocos/ui/CocosGUI.h"

namespace gamer
{

class GamingHUDLayer : public cocos2d::Layer 
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    //static cocos2d::cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static create()" method manually
    CREATE_FUNC(GamingHUDLayer);

private:
    //void onBtnUITestTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_GAMING_HUD_LAYER_H_