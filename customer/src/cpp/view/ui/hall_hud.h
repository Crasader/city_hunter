#ifndef CITY_HUNTER_SRC_HALL_HUD_H_
#define CITY_HUNTER_SRC_HALL_HUD_H_

#include "cocos2d.h"

namespace gamer {

class HallHUD : public cocos2d::Layer 
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	//static cocos2d::cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// implement the "static create()" method manually
	CREATE_FUNC(HallHUD);

private:
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_HALL_HUD_H_