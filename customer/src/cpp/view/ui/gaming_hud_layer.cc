/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  gaming_hud_layer.cc
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

#include "gaming_hud_layer.h"

#include "command_constants.h"
#include "command_manager.h"

namespace gamer 
{

bool GamingHUDLayer::init()
{
    if ( !cocos2d::Layer::init() )
    {
        return false;
    }

    this->setPositionZ(-cocos2d::Director::getInstance()->getZEye());

    auto hud_layer = cocos2d::CSLoader::createNode("ui/gaming/hud/gaming_hud_layer.csb");
    hud_layer->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
    this->addChild(hud_layer);

    return true;
}

} // namespace gamer