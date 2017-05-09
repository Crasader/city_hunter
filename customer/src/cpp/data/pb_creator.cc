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
#include <string>

#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"

#include "actor_cfg.pb.h"
#include "action_cfg.pb.h"
#include "actor_state_cfg.pb.h"
#include "audio_cfg.pb.h"
#include "camera_cfg.pb.h"
#include "map_cfg.pb.h"
#include "model_cfg.pb.h"
#include "space_cfg.pb.h"

using namespace tinyxml2;

namespace gamer
{

const std::string PBCreator::dir_cfg = "E:\\gamer\\cocos2d-x\\project\\city_hunter\\cocos\\res\\cfg\\";

void PBCreator::createMapCfg()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    gamer::cfg::MapCfg map_cfg;   
    gamer::cfg::ActorCfg actor_cfg;

	auto tile_map     = cocos2d::TMXTiledMap::create("map/normal.tmx");
	auto object_group = tile_map->getObjectGroup("objlayer");
    map_cfg.set_map_width(tile_map->getTileSize().width * tile_map->getMapSize().width);
    map_cfg.set_map_height(tile_map->getTileSize().height * tile_map->getMapSize().height);
    
	for (auto& obj : object_group->getObjects())
	{
        auto actor = actor_cfg.add_actor();

		auto dict = obj.asValueMap();        
        // id
        actor->set_id(dict["actor_id"].asInt());

        // actor type
        actor->set_actor_type((gamer::cfg::ActorTypes)dict["actor_type"].asInt());

        // model
        actor->set_model_id((gamer::cfg::ActorTypes)dict["model_id"].asInt());

        // pos rotation
		auto x = dict["x"].asFloat() - 200;
		auto y = map_cfg.map_height() - dict["y"].asFloat() - 200;
		auto pos = new gamer::cfg::Vec3();
		auto rotation = new gamer::cfg::Vec3();
		pos->set_x(x);
		pos->set_y(0);
		pos->set_z(y);
		rotation->set_x(dict["rotation_x"].asFloat());
		rotation->set_y(dict["rotation_y"].asFloat());
		rotation->set_z(dict["rotation_z"].asFloat());
        actor->set_allocated_position(pos);
        actor->set_allocated_rotation(rotation);
		
        // scale
        actor->set_scale(dict["scale"].asFloat());

        // ai
        actor->set_ai_update_interval(dict["ai_update_interval"].asFloat());
        actor->set_first_state_id(dict["first_state_id"].asFloat());
	}
    
    // space ori
    auto space_cfg = new gamer::cfg::SpaceCfg();
    auto vec = new gamer::cfg::Vec3();
    vec->set_x(tile_map->getProperty("space_ori_x").asFloat());
    vec->set_y(tile_map->getProperty("space_ori_y").asFloat());
    vec->set_z(tile_map->getProperty("space_ori_z").asFloat());
    space_cfg->set_allocated_space_ori(vec);

    // space box num
    vec = new gamer::cfg::Vec3();
    vec->set_x(tile_map->getProperty("space_box_num_x").asInt());
    vec->set_y(tile_map->getProperty("space_box_num_y").asInt());
    vec->set_z(tile_map->getProperty("space_box_num_z").asInt());
    space_cfg->set_allocated_space_box_num(vec);

    // space size
    vec = new gamer::cfg::Vec3();
    vec->set_x(tile_map->getProperty("space_size_x").asFloat());
    vec->set_y(tile_map->getProperty("space_size_y").asFloat());
    vec->set_z(tile_map->getProperty("space_size_z").asFloat());
    space_cfg->set_allocated_space_size(vec);

    // cell num
    vec = new gamer::cfg::Vec3();
    vec->set_x(tile_map->getProperty("space_cell_num_x").asInt());
    vec->set_y(tile_map->getProperty("space_cell_num_y").asInt());
    vec->set_z(tile_map->getProperty("space_cell_num_z").asInt());
    space_cfg->set_allocated_space_cell_num(vec);

    map_cfg.set_allocated_space_cfg(space_cfg);

    auto path = dir_cfg + "map_cfg.pb";
    std::fstream output(path.c_str(), std::ios::out | std::ios::binary);
    if ( !map_cfg.SerializeToOstream(&output) )
    {
        assert("creatMapCfg failed !");
    }

    path = dir_cfg + "actor_cfg.pb";
    std::fstream output2(path.c_str(), std::ios::out | std::ios::binary);
    if (!actor_cfg.SerializeToOstream(&output2))
    {
        assert("creatActorCfg failed !");
    }

    output.close();

    google::protobuf::ShutdownProtobufLibrary();
}

/*
void PBCreator::createMapCfg()
{
   GOOGLE_PROTOBUF_VERIFY_VERSION;

    gamer::cfg::MapCfg map_cfg;
    auto actor_cfg = new gamer::cfg::ActorCfg();
    auto space_cfg = new gamer::cfg::SpaceCfg();

    auto tile_map     = cocos2d::TMXTiledMap::create("map/normal.tmx");
    auto object_group = tile_map->getObjectGroup("objlayer");
    map_cfg.set_map_width(tile_map->getTileSize().width * tile_map->getMapSize().width);
    map_cfg.set_map_height(tile_map->getTileSize().height * tile_map->getMapSize().height);

    for (auto& obj : object_group->getObjects())
    {
    // model
    auto dict = obj.asValueMap();
    auto x = dict["x"].asFloat() - 200;
    auto y = map_cfg.map_height() - dict["y"].asFloat() - 200;

    auto actor_model = actor_cfg->add_actor_model();
    actor_model->set_id(dict["actor_id"].asInt());
    actor_model->set_model_file(dict["model_file"].asString());
    actor_model->set_scale(dict["scale"].asFloat());
    actor_model->set_is_ai_enabled(dict["is_ai_enabled"].asBool());

    auto pos = new gamer::cfg::Vec3();
    auto rotation = new gamer::cfg::Vec3();
    pos->set_x(x);
    pos->set_y(0);
    pos->set_z(y);
    rotation->set_x(dict["rotation_x"].asFloat());
    rotation->set_y(dict["rotation_y"].asFloat());
    rotation->set_z(dict["rotation_z"].asFloat());
    actor_model->set_allocated_position(pos);
    actor_model->set_allocated_rotation(rotation);

    // audio
    auto actor_audio = actor_cfg->add_actor_audio();
    actor_audio->set_id(dict["audio_id"].asInt());
    actor_audio->set_normal_atk1(dict["audio_normal_atk1"].asString());
    actor_audio->set_normal_atk2(dict["audio_normal_atk2"].asString());
    actor_audio->set_hurt(dict["audio_normal_hurt1"].asString());
    actor_audio->set_normal_atk_shout(dict["audio_special_atk1"].asString());
    actor_audio->set_special_atk_shout(dict["audio_special_atk2"].asString());
    actor_audio->set_dead(dict["audio_dead"].asString());

    // action
    int i = 1;
    while (true)
    {
    // TODO : use common string format func
    char buf[64];
    snprintf(buf, sizeof("action_%d_id"), "action_%d_id", i);
    std::string s(buf);
    if (dict[s].isNull())
    {
    break;
    }

    auto action = actor_model->add_action();
    action->set_id(dict[s].asInt());

    snprintf(buf, sizeof("action_%d_name"), "action_%d_name", i);
    s = buf;
    action->set_name(dict[s].asString());

    snprintf(buf, sizeof("action_%d_speed"), "action_%d_speed", i);
    s = buf;
    action->set_speed(dict[s].asFloat());

    snprintf(buf, sizeof("action_%d_duration"), "action_%d_duration", i);
    s = buf;
    action->set_duration(dict[s].asFloat());

    snprintf(buf, sizeof("action_%d_from_time"), "action_%d_from_time", i);
    s = buf;
    action->set_from_time(dict[s].asFloat());

    ++i;
    }
    }

    // common action
    auto common_action = new gamer::cfg::CommonAction();
    common_action->set_idle("idle");
    common_action->set_walk("walk");
    common_action->set_dead("dead");
    actor_cfg->set_allocated_common_action(common_action);

    // space ori
    auto vec = new gamer::cfg::Vec3();
    vec->set_x(tile_map->getProperty("space_ori_x").asFloat());
    vec->set_y(tile_map->getProperty("space_ori_y").asFloat());
    vec->set_z(tile_map->getProperty("space_ori_z").asFloat());
    space_cfg->set_allocated_space_ori(vec);

    // space box num
    vec = new gamer::cfg::Vec3();
    vec->set_x(tile_map->getProperty("space_box_num_x").asInt());
    vec->set_y(tile_map->getProperty("space_box_num_y").asInt());
    vec->set_z(tile_map->getProperty("space_box_num_z").asInt());
    space_cfg->set_allocated_space_box_num(vec);

    // space size
    vec = new gamer::cfg::Vec3();
    vec->set_x(tile_map->getProperty("space_size_x").asFloat());
    vec->set_y(tile_map->getProperty("space_size_y").asFloat());
    vec->set_z(tile_map->getProperty("space_size_z").asFloat());
    space_cfg->set_allocated_space_size(vec);

    // cell num
    vec = new gamer::cfg::Vec3();
    vec->set_x(tile_map->getProperty("space_cell_num_x").asInt());
    vec->set_y(tile_map->getProperty("space_cell_num_y").asInt());
    vec->set_z(tile_map->getProperty("space_cell_num_z").asInt());
    space_cfg->set_allocated_space_cell_num(vec);

    map_cfg.set_allocated_actor_cfg(actor_cfg);
    map_cfg.set_allocated_space_cfg(space_cfg);

    //std::string path = dir_cfg + "actor_cfg.pb";
    //std::fstream output(path.c_str(), std::ios::out | std::ios::binary);
    //if (!actor_cfg.SerializeToOstream(&output))
    //{
    //    assert("creatActorCfg failed !");
    //}

    auto path = dir_cfg + "map_cfg.pb";
    std::fstream output(path.c_str(), std::ios::out | std::ios::binary);
    if ( !map_cfg.SerializeToOstream(&output) )
    {
    assert("creatMapCfg failed !");
    }

    output.close();
    //output2.close();
    google::protobuf::ShutdownProtobufLibrary();
}
*/

void PBCreator::createCameraCfg()
{
	std::string path = dir_cfg + "camera_cfg.xml";
	auto xmldoc = new tinyxml2::XMLDocument();
	if (xmldoc->LoadFile(path.c_str()) != 0)
	{
		// TODO : log cfg error
		return;
	}
	auto root = xmldoc->RootElement();

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	gamer::cfg::CameraCfg camera_cfg;

	auto pos = new gamer::cfg::Vec3();
	auto lookat = new gamer::cfg::Vec3();
	pos->set_x(root->FloatAttribute("pos_x"));
	pos->set_y(root->FloatAttribute("pos_y"));
	pos->set_z(root->FloatAttribute("pos_z"));
	lookat->set_x(root->FloatAttribute("lookat_x"));
	lookat->set_y(root->FloatAttribute("lookat_y"));
	lookat->set_z(root->FloatAttribute("lookat_z"));
	camera_cfg.set_allocated_camera_pos(pos);
	camera_cfg.set_allocated_camera_lookat(lookat);

	path = dir_cfg + "camera_cfg.pb";
	std::fstream output(path.c_str(), std::ios::out | std::ios::binary);
	if (!camera_cfg.SerializeToOstream(&output))
	{
		assert("creatCameraCfg failed !");
	}

	output.close();

	google::protobuf::ShutdownProtobufLibrary();
}

void PBCreator::createActorStateCfg()
{
    std::string path = dir_cfg + "actor_state_cfg.xml";
    auto xmldoc = new tinyxml2::XMLDocument();
    if (xmldoc->LoadFile(path.c_str()) != 0)
    {
        // TODO : log cfg error
        return;
    }
    auto root = xmldoc->RootElement();

    GOOGLE_PROTOBUF_VERIFY_VERSION;
    gamer::cfg::ActorStateCfg actor_state_cfg;

    auto xml_ele = root->FirstChildElement();
    while (xml_ele)
    {
        auto state = actor_state_cfg.add_state_cfg();
        state->set_actor_type(xml_ele->IntAttribute("actor_type"));
        state->set_state_id(xml_ele->IntAttribute("state_id"));
        state->set_enter_action(xml_ele->IntAttribute("enter_action"));
        state->set_enter_audio(xml_ele->IntAttribute("enter_audio"));

        auto ele = xml_ele->FirstChildElement();
        while (ele)
        {
            auto next_state = state->add_next_state();
            next_state->set_state_id(ele->IntAttribute("state_id"));
            next_state->set_state_change_requirement(ele->IntAttribute("state_change_requirement"));

            ele = ele->NextSiblingElement();
        }

        xml_ele = xml_ele->NextSiblingElement();
    }

    path = dir_cfg + "actor_state_cfg.pb";
    std::fstream output(path.c_str(), std::ios::out | std::ios::binary);
    if (!actor_state_cfg.SerializeToOstream(&output))
    {
        assert("creatActorStateCfg failed !");
    }
    output.close();

    google::protobuf::ShutdownProtobufLibrary();
}

void PBCreator::createModelCfg()
{
    std::string path = dir_cfg + "model_cfg.xml";
    auto xmldoc = new tinyxml2::XMLDocument();
    if (xmldoc->LoadFile(path.c_str()) != 0)
    {
        // TODO : log cfg error
        return;
    }
    auto root = xmldoc->RootElement();

    GOOGLE_PROTOBUF_VERIFY_VERSION;
    gamer::cfg::ModelCfg model_cfg;

    auto xml_ele = root->FirstChildElement();
    while (xml_ele)
    {
        auto model = model_cfg.add_model();
        model->set_id(xml_ele->IntAttribute("id"));
        model->set_file(xml_ele->Attribute("file"));

        xml_ele = xml_ele->NextSiblingElement();
    }

    path = dir_cfg + "model_cfg.pb";
    std::fstream output(path.c_str(), std::ios::out | std::ios::binary);
    if (!model_cfg.SerializeToOstream(&output))
    {
        assert("creatModelCfg failed !");
    }
    output.close();

    google::protobuf::ShutdownProtobufLibrary();
}

void PBCreator::createAudioCfg()
{
    std::string path = dir_cfg + "audio_cfg.xml";
    auto xmldoc = new tinyxml2::XMLDocument();
    if (xmldoc->LoadFile(path.c_str()) != 0)
    {
        // TODO : log cfg error
        return;
    }
    auto root = xmldoc->RootElement();

    GOOGLE_PROTOBUF_VERIFY_VERSION;
    gamer::cfg::AudioCfg audio_cfg;

    auto xml_ele = root->FirstChildElement();
    while (xml_ele)
    {
        auto audio = audio_cfg.add_audio();
        audio->set_id((gamer::cfg::AudioIDs)xml_ele->IntAttribute("id"));
        audio->set_file(xml_ele->Attribute("file"));

        xml_ele = xml_ele->NextSiblingElement();
    }

    path = dir_cfg + "audio_cfg.pb";
    std::fstream output(path.c_str(), std::ios::out | std::ios::binary);
    if (!audio_cfg.SerializeToOstream(&output))
    {
        assert("creatAudioCfg failed !");
    }
    output.close();

    google::protobuf::ShutdownProtobufLibrary();
}

void PBCreator::createActionCfg()
{
    std::string path = dir_cfg + "action_cfg.xml";
    auto xmldoc = new tinyxml2::XMLDocument();
    if (xmldoc->LoadFile(path.c_str()) != 0)
    {
        // TODO : log cfg error
        return;
    }
    auto root = xmldoc->RootElement();

    GOOGLE_PROTOBUF_VERIFY_VERSION;
    gamer::cfg::ActionCfg action_cfg;

    auto xml_ele = root->FirstChildElement();
    auto last_actor_type = (gamer::cfg::ActorTypes)xml_ele->IntAttribute("actor_type");
    auto actor_action = action_cfg.add_actor_action();
    actor_action->set_actor_type(last_actor_type);
    while (xml_ele)
    {
        auto actor_type = (gamer::cfg::ActorTypes)xml_ele->IntAttribute("actor_type");
        if (last_actor_type != actor_type)
        {
            actor_action = action_cfg.add_actor_action();
            actor_action->set_actor_type(actor_type);
            last_actor_type = actor_type;
        }
        
        auto action = actor_action->add_action();
        action->set_id((gamer::cfg::ActionIDs)xml_ele->IntAttribute("id"));
        action->set_name(xml_ele->Attribute("name"));
        action->set_from_time(xml_ele->FloatAttribute("from_time"));
        action->set_duration(xml_ele->FloatAttribute("duration"));
        action->set_speed(xml_ele->FloatAttribute("speed"));

        xml_ele = xml_ele->NextSiblingElement();
    }

    path = dir_cfg + "action_cfg.pb";
    std::fstream output(path.c_str(), std::ios::out | std::ios::binary);
    if (!action_cfg.SerializeToOstream(&output))
    {
        assert("creatActionCfg failed !");
    }
    output.close();

    google::protobuf::ShutdownProtobufLibrary();
}

} // namespace gamer 