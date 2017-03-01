/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  pb_creator.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-11-09
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "pb_creator.h"

#include <cassert>
#include <fstream>

#include "actor_cfg.pb.h"

namespace gamer
{

const std::string PBCreator::dir_cfg = "E:\\gamer\\cocos2d-x\\project\\city_hunter\\cocos\\res\\cfg\\";

void PBCreator::creatActorCfg()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    gamer::ActorCfg actor_cfg;
    auto actor_audio1 = actor_cfg.add_actor_audio();
    auto actor_audio2 = actor_cfg.add_actor_audio();
    auto actor_audio3 = actor_cfg.add_actor_audio();
    auto actor_model1 = actor_cfg.add_actor_model();
    auto actor_model2 = actor_cfg.add_actor_model();
    auto actor_model3 = actor_cfg.add_actor_model();

    // knight
    actor_audio1->set_id(1000);
    actor_audio1->set_normal_atk1("audio/effects/knight/swish-1.mp3");
    actor_audio1->set_normal_atk2("audio/effects/knight/swish-2.mp3");
    actor_audio1->set_hurt("audio/effects/knight/wounded.mp3");
    actor_audio1->set_normal_atk_shout("audio/effects/knight/normalAttackShout.mp3");
    actor_audio1->set_special_atk_shout("audio/effects/knight/specialAttackShout.mp3");
    actor_audio1->set_dead("audio/effects/knight/dead.mp3");

    actor_model1->set_id(1000);
    actor_model1->set_model_file("model/knight/knight.c3b");
    
    auto vec1 = new ActorModelCfg::Vec3();
    auto vec1_1 = new ActorModelCfg::Vec3();
    
    vec1->set_x(-100);
    vec1->set_y(0);
    vec1->set_z(0);    
    vec1_1->set_x(0);
    vec1_1->set_y(90);
    vec1_1->set_z(0);

    actor_model1->set_allocated_position(vec1);
    actor_model1->set_allocated_rotation(vec1_1);
    actor_model1->set_scale(10);

    auto action = actor_model1->add_action();
    action->set_id(1000);
    action->set_name("attack1");
    action->set_from_time(103 / 30.0f);
    action->set_duration(26 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model1->add_action();
    action->set_id(1001);
    action->set_name("attack2");
    action->set_from_time(130 / 30.0f);
    action->set_duration(24 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model1->add_action();
    action->set_id(1002);
    action->set_name("specail_atk1");
    action->set_from_time(160 / 30.0f);
    action->set_duration(30 / 30.0f);
    action->set_speed(1);

    action = actor_model1->add_action();
    action->set_id(1003);
    action->set_name("specail_atk2");
    action->set_from_time(191 / 30.0f);
    action->set_duration(29 / 30.0f);
    action->set_speed(1);

    action = actor_model1->add_action();
    action->set_id(1004);
    action->set_name("idle");
    action->set_from_time(267 / 30.0f);
    action->set_duration(16 / 30.0f);
    action->set_speed(0.7f);
    
    action = actor_model1->add_action();
    action->set_id(1005);
    action->set_name("walk");
    action->set_from_time(227 / 30.0f);
    action->set_duration(19 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model1->add_action();
    action->set_id(1006);
    action->set_name("defend");
    action->set_from_time(92 / 30.0f);
    action->set_duration(4 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model1->add_action();
    action->set_id(1007);
    action->set_name("knocked");
    action->set_from_time(254 / 30.0f);
    action->set_duration(6 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model1->add_action();
    action->set_id(1008);
    action->set_name("dead");
    action->set_from_time(0 / 30.0f);
    action->set_duration(77 / 30.0f);
    action->set_speed(1);
    
    // archer
    actor_audio2->set_id(1001);
    actor_audio2->set_normal_atk1("audio/effects/archer/swish-3.mp3");
    actor_audio2->set_normal_atk2("audio/effects/archer/swish-4.mp3");
    actor_audio2->set_hurt("audio/effects/archer/hurt.mp3");
    actor_audio2->set_normal_atk_shout("audio/effects/archer/normalAttackShout.mp3");
    actor_audio2->set_special_atk_shout("audio/effects/archer/specialAttackShout.mp3");
    actor_audio2->set_dead("audio/effects/archer/dead.mp3");

    actor_model2->set_id(1001);
    actor_model2->set_model_file("model/archer/archer.c3b");

    auto vec2 = new ActorModelCfg::Vec3();
    auto vec2_1 = new ActorModelCfg::Vec3();
    vec2->set_x(0);
    vec2->set_y(0);
    vec2->set_z(0);
    vec2_1->set_x(0);
    vec2_1->set_y(90);
    vec2_1->set_z(0);
    actor_model2->set_allocated_position(vec2);
    actor_model2->set_allocated_rotation(vec2_1);
    
    action = actor_model2->add_action();  
    action->set_id(1000);
    action->set_name("attack1");
    action->set_from_time(0 / 30.0f);
    action->set_duration(12 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model2->add_action();  
    action->set_id(1001);
    action->set_name("attack2");
    action->set_from_time(12 / 30.0f);
    action->set_duration(12 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model2->add_action();
    action->set_id(1002);
    action->set_name("specail_atk1");
    action->set_from_time(30 / 30.0f);
    action->set_duration(13 / 30.0f);
    action->set_speed(1);

    action = actor_model2->add_action();
    action->set_id(1003);
    action->set_name("specail_atk2");
    action->set_from_time(44 / 30.0f);
    action->set_duration(12 / 30.0f);
    action->set_speed(1);

    action = actor_model2->add_action();
    action->set_id(1004);
    action->set_name("idle");
    action->set_from_time(208 / 30.0f);
    action->set_duration(45/30.0f);
    action->set_speed(0.7f);

    action = actor_model2->add_action();
    action->set_id(1005);
    action->set_name("walk");
    action->set_from_time(110 / 30.0f);
    action->set_duration(20 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model2->add_action();
    action->set_id(1006);
    action->set_name("defend");
    action->set_from_time(70 / 30.0f);
    action->set_duration(25 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model2->add_action();
    action->set_id(1007);
    action->set_name("knocked");
    action->set_from_time(135 / 30.0f);
    action->set_duration(10 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model2->add_action();
    action->set_id(1008);
    action->set_name("dead");
    action->set_from_time(150 / 30.0f);
    action->set_duration(46 / 30.0f);
    action->set_speed(0.7f);

    // mage
    actor_audio3->set_id(1002);
    actor_audio3->set_normal_atk1("audio/effects/mage/ice_1.mp3");
    actor_audio3->set_normal_atk2("audio/effects/mage/ice_2.mp3");
    actor_audio3->set_hurt("audio/effects/mage/hurt.mp3");
    actor_audio3->set_normal_atk_shout("audio/effects/mage/normalAttack.mp3");
    actor_audio3->set_special_atk_shout("audio/effects/mage/specialAttack.mp3");
    actor_audio3->set_dead("audio/effects/mage/dead.mp3");

    actor_model3->set_id(1002);
    actor_model3->set_model_file("model/mage/mage.c3b");
    
    auto vec3 = new ActorModelCfg::Vec3();
    auto vec3_1 = new ActorModelCfg::Vec3();
    vec3->set_x(100);
    vec3->set_y(0);
    vec3->set_z(0);
    vec3_1->set_x(0);
    vec3_1->set_y(90);
    vec3_1->set_z(0);
    actor_model3->set_allocated_position(vec3);
    actor_model3->set_allocated_rotation(vec3_1);

    action = actor_model3->add_action();
    action->set_id(1000);
    action->set_name("attack1");
    action->set_from_time(12 / 30.0f);
    action->set_duration(18 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model3->add_action();
    action->set_id(1001);
    action->set_name("attack2");
    action->set_from_time(31 / 30.0f);
    action->set_duration(49 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model3->add_action();
    action->set_id(1002);
    action->set_name("specail_atk1");
    action->set_from_time(56 / 30.0f);
    action->set_duration(18 / 30.0f);
    action->set_speed(1);

    action = actor_model3->add_action();
    action->set_id(1003);
    action->set_name("specail_atk2");
    action->set_from_time(75 / 30.0f);
    action->set_duration(17 / 30.0f);
    action->set_speed(1);

    action = actor_model3->add_action();
    action->set_id(1004);
    action->set_name("idle");
    action->set_from_time(206 / 30.0f);
    action->set_duration(23 /30.0f);
    action->set_speed(0.7f);

    action = actor_model3->add_action();
    action->set_id(1005);
    action->set_name("walk");
    action->set_from_time(99 / 30.0f);
    action->set_duration(20 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model3->add_action();
    action->set_id(1006);
    action->set_name("defend");
    action->set_from_time(1 / 30.0f);
    action->set_duration(4 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model3->add_action();
    action->set_id(1007);
    action->set_name("knocked");
    action->set_from_time(126 / 30.0f);
    action->set_duration(6 / 30.0f);
    action->set_speed(0.7f);

    action = actor_model3->add_action();
    action->set_id(1008);
    action->set_name("dead");
    action->set_from_time(139 / 30.0f);
    action->set_duration(60 / 30.0f);
    action->set_speed(0.7f);

    // common action
    auto common_action = new gamer::CommonAction();
    //auto common_action = actor_cfg.common_action();
    common_action->set_idle("idle");
    common_action->set_walk("walk");
    common_action->set_dead("dead");
    actor_cfg.set_allocated_common_action(common_action);
    //

    std::string path = dir_cfg + "actor_cfg.pb";
    std::fstream output(path.c_str(), std::ios::out | std::ios::binary);

    if (!actor_cfg.SerializeToOstream(&output)) 
    {        
        assert("creatActorCfg failed !");
    }

    output.close();

    google::protobuf::ShutdownProtobufLibrary();
}

} // namespace gamer 