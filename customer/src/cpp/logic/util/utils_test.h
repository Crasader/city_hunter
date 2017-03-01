/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  utils_test.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-01-16
  @ description:  offer functions for testing functions.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_UTILS_TEST_H_
#define CITY_HUNTER_SRC_UTILS_TEST_H_

#include "cocos2d.h"
#include "draw_node_3d.h"

#include "scene_manager.h"
#include "typedef.h"

namespace gamer
{

namespace utils_test 
{

void drawSpace()
{
    auto scene_mgr = gamer::SceneManager::getInstance();
    
    auto draw_node = scene_mgr->draw_node_3d();
    if (nullptr == draw_node)
        return;

    auto box_num   = scene_mgr->getNumOfSpaceBox();
    auto box_size  = scene_mgr->getSizeOfSpaceBox();
    auto space_ori = scene_mgr->getSpaceOriginOfScene();

    for (int i = 0; i < box_num.x; i++)
    {
        for (int j = 0; j < box_num.y; j++)
        {
            for (int k = 0; k < box_num.z; k++)
            {
                cocos2d::Vec3 extents = cocos2d::Vec3(box_size.x / 2, 
                                                      box_size.y / 2, 
                                                      box_size.z / 2);
                cocos2d::AABB aabb(-extents, extents);
                auto obb = cocos2d::OBB(aabb);
                obb._center = cocos2d::Vec3(space_ori.x + i * box_size.x + box_size.x / 2, 
                                            space_ori.y + j * box_size.y + box_size.y / 2, 
                                            space_ori.z - k * box_size.z - box_size.z / 2);

                cocos2d::Vec3 corners[8] = {};
                obb.getCorners(corners);
                draw_node->drawCube(corners, cocos2d::Color4F(0, 1, 0, 1));               
            } // for 3
        } // for 2
    } // for 1
}

} // namespace utils_test

} // namespace gamer

#endif // CITY_HUNTER_SRC_UTILS_TEST_H_