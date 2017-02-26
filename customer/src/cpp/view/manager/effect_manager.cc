/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  effect_manager.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2016-04-06
 @ description:   see the header file.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#include "effect_manager.h"

#include <algorithm>

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCLabel.h"
#include "cocos/3d/CCBillBoard.h"

#include "attack_command.h"
#include "actor.h"
#include "actor_typedef.h"
#include "command.h"
#include "command_constants.h"
#include "command_listener.h"
#include "command_manager.h"
#include "macros.h"
#include "scene_manager.h"

namespace gamer
{

EffectManager::EffectManager() : num_blood_effects_(10)
{

}

EffectManager::~EffectManager()
{

} 

EffectManager* EffectManager::getInstance()
{
    static EffectManager* effect_manager = nullptr;
    if (nullptr == effect_manager)
    {
        effect_manager = new EffectManager();
        if ( !effect_manager->initListeners() )
        {
            SAFE_DELETE(effect_manager); 
        }
    }
    return effect_manager;
}

void EffectManager::destoryInstance()
{
    auto instance = EffectManager::getInstance();
    SAFE_DELETE(instance);
}

bool EffectManager::init()
{
    // pre create and cache 10 blood effect
    //for (int i = 0; i < 10; i++)
    //{
    //    created_blood_effects_.push_back(createBloodEffect(20));
    //}
    
    return true;
}

bool EffectManager::initListeners()
{
    auto listener = gamer::CommandListener::create(
        CommandIDs::CMD_ID_NORMAL_ATTACK, 
        CALLBACK_SELECTOR_1(EffectManager::onCommandAttack, this),
        "EffectManager::onCommandAttack", 
        1);
    CommandManager::getInstance()->addCmdListener(listener);

    return true;
}

// show attack effect, such as blood effect
void EffectManager::onCommandAttack(gamer::Command* cmd)
{
    auto att_cmd  = static_cast<AttackCommand<ActorType>*>(cmd);
    auto attacker = att_cmd->attacker();
    auto target   = att_cmd->target(); 
    if (nullptr != target)
    {       
        BloodEffect* blood_eff = nullptr;
        if (created_blood_effects_.size() >= num_blood_effects_)
        {
            blood_eff = getBloodEffect(attacker->damage());
            blood_eff->action = createBloodAction();
            blood_eff->blood_node->setOpacity(255);
            blood_eff->blood_node->setPosition3D(cocos2d::Vec3(0, 0, 0));
        }
        else
        {
            blood_eff = createBloodEffect(attacker->damage());
            auto scene = gamer::SceneManager::getInstance()->getRunningScene();
            scene->addChild(blood_eff->root_node);

            created_blood_effects_.push_back(blood_eff);
        }
        
        auto pos = target->entity()->getPosition3D() + cocos2d::Vec3(-10, 50, 0);
        blood_eff->root_node->setPosition3D(pos);          
        blood_eff->blood_node->runAction(blood_eff->action);
    }
}

gamer::EffectManager::BloodEffect* EffectManager::createBloodEffect(int blood_loss)
{
    auto bill_board = cocos2d::BillBoard::create();

    cocos2d::TTFConfig ttfconfig;
    ttfconfig.outlineSize = 7;
    ttfconfig.fontSize = 50;
    ttfconfig.fontFilePath = "fonts/britanic bold.ttf";
    auto blood = cocos2d::Label::createWithTTF(ttfconfig, 
                                               std::to_string(blood_loss), 
                                               cocos2d::TextHAlignment::CENTER, 
                                               400);
    blood->setTag(BloodTags::NORMAL);
    blood->enableOutline(cocos2d::Color4B(255, 0, 0, 255));
    blood->setScale(0.1f);
    blood->setGlobalZOrder(100000);

    //blood->runAction(createBloodAction());
    bill_board->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
    bill_board->addChild(blood);    

    auto blood_eff = new BloodEffect();
    blood_eff->root_node = bill_board;
    blood_eff->blood_node = blood;
    blood_eff->action = createBloodAction();

    return blood_eff;
}

cocos2d::Spawn* EffectManager::createBloodAction()
{
    auto tm = 0.5f;
    auto target_scale = 0.6f;
    auto pos_y = 25;
    auto pos_z = 50;

    auto scale = cocos2d::ScaleTo::create(tm / 2, target_scale);
    auto ease_out = cocos2d::EaseElasticOut::create(scale, 0.4f);
    auto fade_out = cocos2d::FadeOut::create(tm / 2);

    auto sequence = cocos2d::Sequence::create(scale, ease_out, fade_out, nullptr);

    return cocos2d::Spawn::create(sequence,
                                  cocos2d::MoveBy::create(tm, cocos2d::Vec3(0, pos_y, pos_z)),
                                  cocos2d::RotateBy::create(tm, 0), nullptr);
}

// get blood effect from cache, if no effect available, create one, cache it.
gamer::EffectManager::BloodEffect* EffectManager::getBloodEffect(int blood_loss)
{
    if (created_blood_effects_.empty())
        return nullptr;

    BloodEffect* ret = nullptr;
    auto blood = std::find_if(created_blood_effects_.begin(), 
                              created_blood_effects_.end(), 
                              [&](BloodEffect* be) -> bool
                              {
                                  if (be->available)
                                  {
                                      return true;
                                  }
                                  return false;
                               });
    if (created_blood_effects_.end() != blood)
    {
        //(*blood)->blood_loss = blood_loss;
        (*blood)->blood_node->setString(std::to_string(blood_loss));
        (*blood)->available = false;
        ret = *blood;
    }
    else
    {
        std::for_each(created_blood_effects_.begin(), 
                      created_blood_effects_.end(),
                      [&](BloodEffect* be)
                      {  
                          be->available = true;      
                      });
        blood = created_blood_effects_.begin();  
        (*blood)->blood_node->setString(std::to_string(blood_loss));
        (*blood)->available = false;
        ret = *blood;
    }
   
    return ret;
}

} // namespace gamer