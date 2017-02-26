/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  space_partition_test_scene.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-24
  @ description:  scene for testing space partition algorithms.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_SPACE_PARTITION_TEST_SCENE_H_
#define CITY_HUNTER_SRC_SPACE_PARTITION_TEST_SCENE_H_

#include "cocos2d.h"
#include "cocos/editor-support/cocostudio/CocoStudio.h"
#include "cocos/ui/CocosGUI.h"

#include "actor_typedef.h"
#include "graph_typedef.h"

namespace cocos2d 
{
    
class DrawNode3D;
//class Sprite3D;
//class Vec3;
//class OBB;
//class AABB;
    
}

namespace gamer
{

class SpacePartitionTestScene : public cocos2d::Layer
{
public:
    ~SpacePartitionTestScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init() override;  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // implement the "static node()" method manually
    CREATE_FUNC(SpacePartitionTestScene);

private:
    //typedef Actor<cocos2d::Sprite3D> ActorType;
    
    //typedef BoxSpacePartition<ActorType, cocos2d::Vec3, cocos2d::OBB, cocos2d::AABB> SpacePartition;

    void initVars();

    void drawSpaceAndAddEntities();

    void createSpace();
    
    graph::SpacePartition3D* space_partition_;

    int num_boxes_x_;
    int num_boxes_y_;
    int num_boxes_z_;

    float space_size_x_;
    float space_size_y_;
    float space_size_z_;

    float box_size_x_;
    float box_size_y_;
    float box_size_z_; 

    cocos2d::DrawNode3D* draw3d_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_SPACE_PARTITION_TEST_SCENE_H_