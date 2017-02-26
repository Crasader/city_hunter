/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  space_partition_test_scene.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-24
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "space_partition_test_scene.h"

#include "cocos/3d/CCSprite3D.h"
#include "cocos/3d/CCOBB.h"
#include "cocos/3d/CCAABB.h"
#include "cocos/3d/DrawNode3D.h"

#include "actor.h"
#include "space_partition.h"

namespace gamer
{

SpacePartitionTestScene::~SpacePartitionTestScene()
{

}

cocos2d::Scene* SpacePartitionTestScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    SpacePartitionTestScene *layer = SpacePartitionTestScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool SpacePartitionTestScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    //auto sprite = cocos2d::Sprite3D::create("model/archer/archer.c3b");
    //this->addChild(sprite);
    //sprite->setPosition3D(cocos2d::Vec3(200, 200, 0));

    //auto draw3d = cocos2d::DrawNode3D::create();
    //this->addChild(draw3d);

    initVars();

    drawSpaceAndAddEntities();

    return true;
}

void SpacePartitionTestScene::initVars()
{
    num_boxes_x_ = 6;
    num_boxes_y_ = 3;
    num_boxes_z_ = 3;

    space_size_x_ = 480;
    space_size_y_ = 240;
    space_size_z_ = 240;

    box_size_x_ = space_size_x_ / num_boxes_x_;
    box_size_y_ = space_size_y_ / num_boxes_y_;
    box_size_z_ = space_size_z_ / num_boxes_z_;

    auto visible_size = cocos2d::Director::getInstance()->getVisibleSize();
    auto visible_ori  = cocos2d::Director::getInstance()->getVisibleOrigin();

    float offest_x = visible_ori.x + (visible_size.width - space_size_x_) / 2; 
    float offest_y = visible_ori.y + (visible_size.height - space_size_y_) / 2;

    space_partition_ = new graph::SpacePartition3D(space_size_x_,
                                          space_size_y_, 
                                          space_size_z_, 
                                          num_boxes_x_, 
                                          num_boxes_y_, 
                                          num_boxes_z_, 
                                          cocos2d::Vec3(offest_x, offest_y, 0), 
                                          54);

    draw3d_ = cocos2d::DrawNode3D::create();
    this->addChild(draw3d_);
}

void SpacePartitionTestScene::drawSpaceAndAddEntities()
{
    auto visible_size = cocos2d::Director::getInstance()->getVisibleSize();
    auto visible_ori  = cocos2d::Director::getInstance()->getVisibleOrigin();

    float offest_x = visible_ori.x + (visible_size.width - space_size_x_) / 2; 
    float offest_y = visible_ori.y + (visible_size.height - space_size_y_) / 2;

    for (int i = 0; i < num_boxes_x_; i++)
    {
        for (int j = 0; j < num_boxes_y_; j++)
        {
            for (int k = 0; k < num_boxes_z_; k++)
            {
                cocos2d::Vec3 extents = cocos2d::Vec3(box_size_x_ / 2, 
                                                      box_size_y_ / 2, 
                                                      box_size_z_ / 2);
                cocos2d::AABB aabb(-extents, extents);
                auto obb = cocos2d::OBB(aabb);
                obb._center = cocos2d::Vec3(offest_x + i * box_size_x_ + box_size_x_ / 2, 
                                            offest_y + j * box_size_y_ + box_size_y_ / 2 , 
                                            k * box_size_z_ + box_size_z_ / 2);

                cocos2d::Vec3 corners[8] = {};
                obb.getCorners(corners);
                draw3d_->drawCube(corners, cocos2d::Color4F(0, 1, 0, 1));

                //auto sprite = cocos2d::Sprite3D::create("model/archer/archer.c3b");
                //this->addChild(sprite);
                //cocos2d::Vec3 pos(obb._center);
                //pos.y -= box_size_y_ / 2;
                //sprite->setPosition3D(pos);

                //ActorType* actor = ActorType::create("model/archer/archer.c3b");
                auto actor = ActorType::create("model/archer/archer.c3b");
                this->addChild(actor->entity());

                actor->set_ai_enabled(false);

                cocos2d::Vec3 pos(obb._center);
                pos.y -= box_size_y_ / 2;
                actor->entity()->setPosition3D(pos);

                space_partition_->addEntity(actor);                
            }
        }
    }

    cocos2d::Vec3 target_pos(offest_x + box_size_x_ / 2, 
                      offest_y + box_size_y_ / 2 , 
                      2.5f * box_size_z_);
    float query_radius = box_size_x_ / 2 + 20;
    space_partition_->calculateNeighbors(target_pos, query_radius);

    
    cocos2d::Vec3 extents = cocos2d::Vec3(query_radius, 
                                          query_radius, 
                                          query_radius);
    cocos2d::AABB aabb(-extents, extents);
    auto obb = cocos2d::OBB(aabb);
    obb._center = target_pos;

    cocos2d::Vec3 corners[8] = {};
    obb.getCorners(corners);
    draw3d_->drawCube(corners, cocos2d::Color4F(0, 0, 1, 1));

    //cocos2d::log("Neighbors : %d", space_partition_->getNumOfNeighbors());
}

void SpacePartitionTestScene::createSpace()
{

}

} // namespace gamer