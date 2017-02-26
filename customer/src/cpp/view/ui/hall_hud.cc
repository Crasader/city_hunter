#include "hall_hud.h"

namespace gamer {

bool HallHUD::init()
{
	if ( !cocos2d::Layer::init() )
	{
		return false;
	}

	return true;
}

} // namespace gamer