/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	  gaming_scene.h
@ author:		  Connor
@ version:	  1.0.0
@ date:		  2015-10-09
@ description:  see the header file.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#include "gaming_scene.h"

#include <cmath>
#include <string>

#include "actor.h"
#include "actor_manager.h"
#include "actor_typedef.h"
#include "camera_manager.h"
#include "data_manager.h"
#include "event_headers.h"
#include "graph_typedef.h"
#include "macros.h"
#include "space_partition.h"
#include "scene_constants.h"
#include "util_graph.h"

namespace gamer
{

GamingScene::~GamingScene()
{
	SAFE_DELETE(sparse_graph_);
}

cocos2d::Scene* GamingScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = cocos2d::Scene::create();

	// 'layer' is an autorelease object
	GamingScene* layer = GamingScene::create();
	layer->setTag(gamer::LayerTags::GAMING_SCENE_ROOT_LAYER);

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool GamingScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	initVars();

	initListeners();

	// touch event listeners
	//initTouchEventListeners();

	initDrawPathLayer();

	initGraphAlgorithms();

	drawTerrain();

	initCamera();

	//drawPathOfAStarAlgorithms();

	//int obstacle = utils_graph::getNodeIndexByPos(cocos2d::Vec3(0, 0, 0));
	//int obstacle = getNodeIndexByPos(cocos2d::Vec3(0, 0, 0));
	//auto graph = PathFinder::getInstance()->graph();
	//graph->getNode(obstacle).set_enabled(false);

	return true;
}

void GamingScene::initVars()
{
	touched_btn_type_ = TouchedButtonTypes::BTN_UNKNOWN;

	auto space_cfg = gamer::DataManager::getInstance()->space_cfg();

	space_ori_.x = space_cfg.space_ori().x();
	space_ori_.y = space_cfg.space_ori().y();
	space_ori_.z = space_cfg.space_ori().z();

	num_space_box_.x = space_cfg.space_box_num().x();
	num_space_box_.y = space_cfg.space_box_num().y();
	num_space_box_.z = space_cfg.space_box_num().z();

	space_size_.x = space_cfg.space_size().x();
	space_size_.y = space_cfg.space_size().y();
	space_size_.z = space_cfg.space_size().z();

	if (0 == num_space_box_.x)
	{
		num_space_box_.x = 1;
		// TODO : log cfg error
	}

	if (0 == num_space_box_.y)
	{
		num_space_box_.y = 1;
		// TODO : log cfg error
	}

	if (0 == num_space_box_.z)
	{
		num_space_box_.z = 1;
		// TODO : log cfg error
	}

	size_space_box_.x = space_size_.x / num_space_box_.x;
	size_space_box_.y = space_size_.y / num_space_box_.y;
	size_space_box_.z = space_size_.z / num_space_box_.z;

	cells_num_.x = space_cfg.space_cell_num().x();
	cells_num_.y = space_cfg.space_cell_num().y();
	cells_num_.z = space_cfg.space_cell_num().z();

	if (0 == cells_num_.x)
	{
		cells_num_.x = 1;
		// TODO : log cfg error
	}

	if (0 == cells_num_.z)
	{
		cells_num_.z = 1;
		// TODO : log cfg error
	}

	cell_.w = space_size_.x / cells_num_.x;
	cell_.h = space_size_.z / cells_num_.z;

	space_partition_ = new graph::SpacePartition3D(space_size_.x,
		space_size_.y,
		space_size_.z,
		num_space_box_.x,
		num_space_box_.y,
		num_space_box_.z,
		cocos2d::Vec3(space_ori_.x, space_ori_.y, space_ori_.z),
		20); // TODO : read from cfg
}

void GamingScene::initListeners()
{
	auto listener = EventListener::create(
		EventIDs::EVENT_ACTORS_CREATED,
		CALLBACK_SELECTOR_1(GamingScene::onEventActorsCreated, this),
		"GamingScene::onEventActorsCreated",
		1);

	EventManager::getInstance()->addEventListener(listener);
}

void GamingScene::initTouchEventListeners()
{
	auto listener = cocos2d::EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(GamingScene::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(GamingScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// key press event listener
	//auto listener2 = cocos2d::EventListenerMouse::create();
	//listener2->onMouseUp = [&](cocos2d::Event* event){ onMouseUp(event); };
	//    //CC_CALLBACK_2(GamingScene::onMouseUp, this);
	//this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
	//event_listener_mouse_ = listener2;
}

void GamingScene::initDrawPathLayer()
{
	draw_path_layer_ = cocos2d::Layer::create();
	this->addChild(draw_path_layer_);

	draw_node_ = cocos2d::DrawNode3D::create();
	draw_path_layer_->addChild(draw_node_);
}

void GamingScene::initGraphAlgorithms()
{
	sparse_graph_ = new graph::SparseGraph3D(false);
	PathFinder::getInstance()->set_graph(sparse_graph_);

	// create all the nodes
	for (int row = 0; row < cells_num_.z; row++)
	{
		for (int col = 0; col < cells_num_.x; col++)
		{
			cocos2d::Vec3 pos(space_ori_.x + col * cell_.w + cell_.w / 2.0,
				0,
				space_ori_.z - row * cell_.h - cell_.h / 2.0);

			sparse_graph_->addNode(graph::NavGraphNode<cocos2d::Vec3>(
				sparse_graph_->next_free_node(),
				pos));
		}
	}

	// create all the edges
	for (int row = 0; row < cells_num_.z; row++)
	{
		for (int col = 0; col < cells_num_.x; col++)
		{
			//auto pos = cocos2d::Vec3();
			gamer::util_graph::addAllEdgesToNode(*sparse_graph_,
				//pos,
				row,
				col,
				cells_num_.x,
				cells_num_.z);
		}
	}
}

bool GamingScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	cocos2d::log("[GamingScene::onTouchBegan]");

	//cocos2d::Point touch_point = touch->getLocationInView();
	//touch_point = cocos2d::Director::getInstance()->convertToGL(touch_point); 

	//if (!isTouchValid(touch_point))
	//    return false;

	return true;
}

void GamingScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	cocos2d::log("[GamingScene::onTouchMoved]");
}

void GamingScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	cocos2d::log("[GamingScene::onTouchEnded]");

	if (TouchedButtonTypes::BTN_UNKNOWN == touched_btn_type_)
	{
		cocos2d::log("[GamingScene::onTouchEnded] TouchedButtonTypes::BTN_UNKNOWN == touched_btn_type_");
		return;
	}

	cocos2d::Point touch_point = touch->getLocationInView();
	touch_point = cocos2d::Director::getInstance()->convertToGL(touch_point);

	//if (!isTouchValid(touch_point))
	//    return;

	cocos2d::log("[GamingScene::onTouchEnded] touch_point.x : %f", touch_point.x);
	cocos2d::log("[GamingScene::onTouchEnded] touch_point.y : %f", touch_point.y);

	fixTouchedPoint(touch_point);

	cocos2d::log("[GamingScene::onTouchEnded] affter fixed, touch_point.x : %f", touch_point.x);
	cocos2d::log("[GamingScene::onTouchEnded] affter fixed, touch_point.y : %f", touch_point.y);

	//int index = getNodeIndexByPos(touch_point);
	//cocos2d::log("[GamingScene::onTouchEnded] index of touched node : %d", index);

	if (TouchedButtonTypes::BTN_SOURCE == touched_btn_type_)
	{
		image_red_source_->setPosition(touch_point);
		image_red_source_->setVisible(true);

		//source_ = getNodeIndexByPos(touch_point);

		drawPathOfAStarAlgorithms();
	}
	else if (TouchedButtonTypes::BTN_TARGET == touched_btn_type_)
	{
		image_purple_target_->setPosition(touch_point);
		image_purple_target_->setVisible(true);

		//target_ = getNodeIndexByPos(touch_point);

		drawPathOfAStarAlgorithms();
	}
	else if (TouchedButtonTypes::BTN_OBSTACLE == touched_btn_type_)
	{
		//image_gray_obstacle_->setPosition(touch_point);
		//image_gray_obstacle_->setVisible(true);
		auto img_obstacle = cocos2d::ui::ImageView::create("icon/rectangle_10x10_gray.png",
			cocos2d::ui::Widget::TextureResType::LOCAL);
		if (nullptr != img_obstacle)
		{
			this->addChild(img_obstacle);
			img_obstacle->setPosition(touch_point);
			img_obstacle->setVisible(true);
		}

		// remove the node from the graph
		//sparse_graph_->removeNode(getNodeIndexByPos(touch_point));

		drawPathOfAStarAlgorithms();
	}
}

void GamingScene::onEventActorsCreated(gamer::Event* event)
{
	//auto actors = gamer::ActorManager::getInstance()->created_actors();

	//std::for_each(actors.begin(), 
	//              actors.end(), 
	//              [&](std::pair<int, ActorType*> a)
	//              { 
	//                  addActorToSpace(a.second);
	//                  // test
	//                  //a.second->initPath2Target();
	//              });

	//cocos2d::Vec3 target_pos(-100, 0, 0);
	//float query_radius = space_size_.x / 2;
	//space_partition_->calculateNeighbors(target_pos, query_radius);

	//cocos2d::Vec3 extents = cocos2d::Vec3(query_radius, query_radius, query_radius);
	//cocos2d::AABB aabb(-extents, extents);
	//auto obb = cocos2d::OBB(aabb);
	//obb._center = target_pos;

	//cocos2d::Vec3 corners[8] = {};
	//obb.getCorners(corners);
	//draw_node_->drawCube(corners, cocos2d::Color4F(0, 0, 1, 1));

	// test
	//source_ = utils_graph::getNodeIndexByPos(cocos2d::Vec3(-100, 0, 0));
	//target_ = utils_graph::getNodeIndexByPos(cocos2d::Vec3(100, 0, 0));

	//drawPathOfAStarAlgorithms();

	//int obstacle = utils_graph::getNodeIndexByPos(cocos2d::Vec3(0, 0, 0));
	//auto graph = PathFinder::getInstance()->graph();
	//graph->getNode(obstacle).set_enabled(false);

	//cocos2d::log("Neighbors : %d", space_partition_->getNumOfNeighbors(*actors.begin()->second));
}

bool GamingScene::isTouchValid(const cocos2d::Point& pos) const
{
	//auto win_size = cocos2d::Director::getInstance()->getWinSize();
	//auto origin   = cocos2d::Director::getInstance()->getVisibleOrigin();

	if (pos.x >= space_ori_.x &&
		pos.x <= space_ori_.x + cells_num_.x * cell_.w &&
		pos.y >= space_ori_.y &&
		pos.y <= space_ori_.y + cells_num_.y * cell_.w)
	{
		return true;
	}

	return false;
}

void GamingScene::fixTouchedPoint(cocos2d::Point& pos)
{
	float interval = cell_.w;
	int nx = (int(pos.x - space_ori_.x)) / interval;
	int ny = (int(pos.y - space_ori_.y)) / interval;

	pos.x = space_ori_.x + nx * interval + interval / 2;
	pos.y = space_ori_.y + ny * interval + interval / 2;
}

//int GamingScene::getNodeIndexByPos(const cocos2d::Vec3& pos)
//{
//    int complete_row   = (space_ori_.z - pos.z - cell_.h / 2.0) / cell_.h;
//    int incpmplete_row = (pos.x - space_ori_.x - cell_.w / 2.0) / cell_.w;
//    
//    int index = complete_row * num_cells_.x + incpmplete_row;
//    if (index < 0)
//    {
//        index = 0;
//    }
//    
//    return index;
//}

void GamingScene::drawTerrain()
{
	drawGrids();
}

void GamingScene::drawGrids()
{
	auto draw_node = cocos2d::DrawNode3D::create();
	draw_node->setName("2017");
	this->addChild(draw_node);
	/*
	// draw x
	for (int j = -20; j <= 20; j++)
	{
		draw_node->drawLine(cocos2d::Vec3(-100, 0, 5 * j), cocos2d::Vec3(100, 0, 5 * j), cocos2d::Color4F(1, 0, 0, 1));
	}
	// draw z
	for (int j = -20; j <= 20; j++)
	{
		draw_node->drawLine(cocos2d::Vec3(5 * j, 0, -100), cocos2d::Vec3(5 * j, 0, 100), cocos2d::Color4F(0, 0, 1, 1));
	}
	*/
	// draw x
	for (int i = 0; i <= cells_num_.z; i++)
	{
		draw_node->drawLine(cocos2d::Vec3(space_ori_.x, 0, space_ori_.z - cell_.h * i),
							cocos2d::Vec3(space_ori_.x + space_size_.x, 
                                          0, 
                                          space_ori_.z - cell_.h * i),
							cocos2d::Color4F(1, 0, 0, 1));
	}
	// draw z
	for (int i = 0; i <= cells_num_.x; i++)
	{
		draw_node->drawLine(cocos2d::Vec3(space_ori_.x + cell_.w * i, 0, space_ori_.z), 
                            cocos2d::Vec3(space_ori_.x + cell_.w * i, 
                                          0, 
                                          space_ori_.z - space_size_.z),
                            cocos2d::Color4F(0, 0, 1, 1));
	}
}

void GamingScene::drawPath()
{
	gamer::util_graph::drawPath(path_,
		*sparse_graph_,
		*draw_node_,
		cocos2d::Color4F::GREEN);
}

void GamingScene::drawPathOfAStarAlgorithms()
{
	path_.clear();
	//path_.clear();

	graph::AStarSearch astar(*sparse_graph_, source_, target_);
	path_ = astar.getPathToTarget();
	drawPath();
	//graph::AStarSearch astar(*sparse_graph_, source_, target_);
	//path_ = astar.getPathToTarget();
	//drawPath();

	PathFinder::getInstance()->set_path(path_);
	//PathFinder::getInstance()->set_path(path_);
}

void GamingScene::initCamera()
{
	/*
	auto size = cocos2d::Director::getInstance()->getWinSize();
	camera_ = cocos2d::Camera::createPerspective(60, size.width / size.height, 1, 1000);
	//camera_ = cocos2d::Camera::createPerspective(60, 1.5f, 1, 1000);
	this->addChild(camera_);

	//auto center = cocos2d::Vec3(size.width / 2, size.height / 2, 0);
	camera_->setPosition3D(cocos2d::Vec3(0, 130, 130));
	//camera_->setPosition3D(cocos2d::Vec3(0, 130, 300));
	camera_->lookAt(cocos2d::Vec3::ZERO);
	*/

	//CameraManager::getInstance()->initCamera();
}

void GamingScene::initActors()
{

}

void GamingScene::drawSpace()
{
	for (int i = 0; i < num_space_box_.x; i++)
	{
		for (int j = 0; j < num_space_box_.y; j++)
		{
			for (int k = 0; k < num_space_box_.z; k++)
			{
				cocos2d::Vec3 extents = cocos2d::Vec3(size_space_box_.x / 2,
					size_space_box_.y / 2,
					size_space_box_.z / 2);
				cocos2d::AABB aabb(-extents, extents);
				auto obb = cocos2d::OBB(aabb);
				obb._center = cocos2d::Vec3(space_ori_.x + i * size_space_box_.x + size_space_box_.x / 2,
					space_ori_.y + j * size_space_box_.y + size_space_box_.y / 2,
					space_ori_.z - k * size_space_box_.z - size_space_box_.z / 2);

				cocos2d::Vec3 corners[8] = {};
				obb.getCorners(corners);
				draw_node_->drawCube(corners, cocos2d::Color4F(0, 1, 0, 1));

				//ActorType* actor = ActorType::create("model/archer/archer.c3b");
				//this->addChild(actor->entity());

				//actor->set_ai_enabled(false);

				//cocos2d::Vec3 pos(obb._center);
				//pos.y -= size_space_box_.y / 2;
				//actor->entity()->setPosition3D(pos);

				//space_partition_->addEntity(*actor);                
			}
		}
	}
}

void GamingScene::addActorToSpace(ActorType* actor)
{
	if (nullptr != space_partition_)
	{
		space_partition_->addEntity(actor);
	}
}

} // namespace gamer