/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  effect_manager.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2016-04-06
 @ description:   effect manager, such as blood effect, skill effect, ect.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#ifndef CITY_HUNTER_SRC_EFFECT_MANAGER_H_
#define CITY_HUNTER_SRC_EFFECT_MANAGER_H_

#include <vector>

#include "typedef.h"

namespace cocos2d
{
class Action;
class BillBoard; 
class Label;
class Ref;
class Spawn;
};

namespace gamer
{

class Command;

class EffectManager
{
public:
    typedef struct BloodEff
    {
        BloodEff()
            :blood_node(nullptr)
            ,action(nullptr)
            ,available(true)
            //,blood_loss(20)
        {
        }
        cocos2d::BillBoard* root_node;
        cocos2d::Label* blood_node;
        cocos2d::Action* action;
        //int blood_loss;
        bool available;
    } BloodEffect;

    ~EffectManager();

    static EffectManager* getInstance();

    static void destoryInstance();

    bool init();

private:
    enum BloodTags
    {
        NORMAL
    };

    EffectManager();

    bool initListeners();

    void onCommandAttack(gamer::Command* cmd);

    cocos2d::Spawn* createBloodAction();

    gamer::EffectManager::BloodEffect* createBloodEffect(int blood_loss);

    BloodEffect* getBloodEffect(int blood_loss);

    std::vector<BloodEffect*> created_blood_effects_;

    uint num_blood_effects_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_EFFECT_MANAGER_H_