/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  space_partition.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-21
  @ description:  offer space partition algorithms, mainly use to find attack target.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_SPACE_PARTITION_H_
#define CITY_HUNTER_SRC_SPACE_PARTITION_H_

#include <cassert>
#include <list>
#include <vector>

#include "cocos/3d/CCAABB.h"
#include "cocos/3d/CCOBB.h"

#include "graph_typedef.h"

namespace gamer
{

// use for 3d space, "BoundingBox" is a 3d bounding box type such as AABB, OBB
template<typename Entity, typename BoundingBox, typename ExtraInfo = void*>
struct Box
{
    // AABB or OBB
    Box(const BoundingBox& bb) 
        :box(bb)
    {

    }

    // AABB
//    Box(const PositionType& min, const PositionType& max) 
//        :box(min, max)
//    {
//
//    }

    std::list<Entity*> entity_list;

    BoundingBox box;
};

// partition specialization for OBB of cocos
template<typename Entity>
struct Box<Entity, cocos2d::OBB, cocos2d::AABB>
{
    Box(const cocos2d::OBB& bb) 
        :box(bb)
    {

    }

//    Box(const cocos2d::Vec3& min, const cocos2d::Vec3& max) 
//    {
//        //cocos2d::Vec3 extents = cocos2d::Vec3(10, 10, 10);
//        //cocos2d::AABB aabb(-extents, extents);
//        //auto obb = cocos2d::OBB(aabb);
//
//        cocos2d::AABB aabb(min, max);
//        box = cocos2d::OBB(aabb);
//    }

    std::list<Entity*> entity_list;

    cocos2d::OBB box;
};

// use for 3d space, this is partition specialization for cocos
// TODO : create the common BoxSpacePartition
template <typename Entity, typename PositionType, typename BoundingBox, typename ExtraInfo = void*>
class BoxSpacePartition
{
public:
    BoxSpacePartition(float size_x,      // size x of the game space
                      float size_y, 
                      float size_z,
                      int num_boxes_x,   // number of boxes in x
                      int num_boxes_y,
                      int num_boxes_z,
                      const PositionType& origin, // origin of game space
                      int max_entities)           // maximum number of entities to add
        :space_size_x_(size_x)
        ,space_size_y_(size_y)
        ,space_size_z_(size_z)
        ,num_boxes_x_(num_boxes_x)
        ,num_boxes_y_(num_boxes_y)
        ,num_boxes_z_(num_boxes_z)
        ,space_origin_(origin)
        ,neighbors_(max_entities, nullptr)
    {
        init();
    }

    // adds entities to the class by allocating them to the appropriate Box
    inline void addEntity(Entity* ent)
    {
        //assert(nullptr != ent.entity());
        assert(nullptr != ent && nullptr != ent->entity());

        int index = getIndexByPosition(ent->entity()->getPosition3D());

        boxes_[index].entity_list.push_back(ent);
    }

    // update an Entity's box by calling this from your Entity's Update method 
    void updateEntity(const Entity* ent, PositionType old_pos)
    {
        if (nullptr == ent || nullptr == ent->entity())
            return;

        // if the index for the old pos and the new pos are not equal then
        // the entity has moved to another box
        int old_index = getIndexByPosition(old_pos);
        int new_index = getIndexByPosition(ent->entity()->getPosition3D());

        if (new_index == old_index) 
            return;

        // the entity has moved into another box so delete from current box
        // and add to new one
        boxes_[old_index].entity_list.remove(ent);
        boxes_[new_index].entity_list.push_back(ent);
    }

    // this method calculates all a target's neighbors and stores them in
    // the neighbor vector. after you have called this method use the begin, 
    // next and end methods to iterate through the vector.
    void calculateNeighbors(const PositionType& target_pos, float query_radius)
    {
        typename std::vector<Entity*>::iterator cur_neighbor = neighbors_.begin();

        cocos2d::Vec3 extents = cocos2d::Vec3(query_radius, 
                                              query_radius, 
                                              query_radius);
        cocos2d::AABB aabb(-extents, extents);
        auto obb = cocos2d::OBB(aabb);
        obb._center = target_pos;

        //gamer::Box<Entity, cocos2d::Vec3, cocos2d::OBB, cocos2d::AABB> query_box(obb);
        gamer::Box<Entity, cocos2d::OBB, cocos2d::AABB> query_box(obb);
        
        // iterate through each cell and test to see if its bounding box overlaps
        // with the query box. If it does and it also contains entities then
        // make further proximity tests.
        for (auto cur_box = boxes_.begin(); cur_box != boxes_.end(); ++cur_box)
        {
            // test to see if this box contains members and if it overlaps the query box
            if (cur_box->box.intersects(query_box.box) &&
                !cur_box->entity_list.empty())
            {
                // add any entities found within query radius to the neighbor list
                auto cur_entity = cur_box->entity_list.begin();
                for (; cur_entity != cur_box->entity_list.end(); ++cur_entity)
                {
                    auto ent = (*cur_entity)->entity();
                    if (ent->getPosition3D().distanceSquared(target_pos) <= 
                        query_radius * query_radius)
                    {
                        *cur_neighbor++ = *cur_entity;
                    }
                } // end for 2
            }
        } // end for 1

        // mark the end of the list with a zero
        //*cur_neighbor = 0;
        if (cur_neighbor != neighbors_.end())
            *cur_neighbor = nullptr;
    }

    // returns a reference to the entity at the front of the neighbor vector
    inline Entity* begin() 
    { 
        cur_neighbor_ = neighbors_.begin(); 
        return *cur_neighbor_; 
    }

    // returns the next Entity in the neighbor vector
    inline Entity* next() 
    { 
        if (cur_neighbor_ != neighbors_.end())
        {
            ++cur_neighbor_;  
            if (end())
            {
                return nullptr;
            }
            else
            {
                return *cur_neighbor_;
            }
        }
        return nullptr;
    }

    // returns true if the end of the vector is found (a zero value marks the end)
    //inline bool end() { return (cur_neighbor_ == neighbors_.end()) || (0 == *cur_neighbor_); }   
    inline bool end() { return (cur_neighbor_ == neighbors_.end()) || (nullptr == (*cur_neighbor_)); }   

    // get num of neighbors
    int getNumOfNeighbors(const Entity* self)  
    { 
        if (nullptr == self)
            return 0;

        int count = 0;
        auto cur = begin();
        while (nullptr != cur)
        {
            if (self->id() != cur->id())
            {
                 ++count;
            }
           
            cur = next();
        }

        return count;
    }

    // get neighbors
    std::vector<Entity*> getNeighbors(const Entity* self)  
    { 
        std::vector<Entity*> neighbors;
        if (nullptr == self)
            return neighbors;

        auto cur = begin();
        while (nullptr != cur)
        {
            if (self->id() != cur->id())
            {
                neighbors.push_back(cur);
            }
            
            cur = next();
        }

        return neighbors;
    }

    // get alive neighbors
    std::vector<Entity*> getAliveNeighbors(const Entity* self)  
    { 
        std::vector<Entity*> neighbors;
        if (nullptr == self)
            return neighbors;

        auto cur = begin();
        while (nullptr != cur)
        {
            if (self->id() != cur->id() && cur->hp() > 0)
            {
                neighbors.push_back(cur);
            }

            cur = next();
        }

        return neighbors;
    }

    // remove all the boxes of entities
    void clearBoxes()
    {
        for (auto it = boxes_.begin(); it != boxes_.end(); ++it)
        {
            it->entity_list.clear();
        }
    }

private:
    void init()
    {
        box_size_x_ = space_size_x_ / num_boxes_x_;
        box_size_y_ = space_size_y_ / num_boxes_y_;
        box_size_z_ = space_size_z_ / num_boxes_z_;

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
                    cocos2d::OBB obb = cocos2d::OBB(aabb);
                    obb._center = cocos2d::Vec3(space_origin_.x + i * box_size_x_ + box_size_x_ / 2, 
                                                space_origin_.y + j * box_size_y_ + box_size_y_ / 2, 
                                                space_origin_.z - k * box_size_z_ - box_size_z_ / 2);
                    //boxes_.push_back(Box<Entity, PositionType, BoundingBox, ExtraInfo>(obb));
                    boxes_.push_back(Box<Entity, BoundingBox, ExtraInfo>(obb));
                }
            }
        }
    }

    // given a position in the game space this method determines the relevant Box's index,
    // make sure that the index must >= 0 and <= boxes_.size() - 1
    inline int getIndexByPosition(const PositionType& pos) const
    {
        int index = (int)(num_boxes_z_ * (pos.z - space_origin_.z) / space_size_z_) +
                    ((int)(num_boxes_y_ * (pos.y - space_origin_.y) / space_size_y_) * num_boxes_z_) +
                    ((int)(num_boxes_x_ * (pos.x - space_origin_.x) / space_size_x_) * (num_boxes_y_ * num_boxes_z_));

        // if the entity's position is equal to 
        // vector3d(space_size_x_, space_size_y_, space_size_z_)
        // then the index will overshoot. we need to check for this and adjust
        if (index > (int)boxes_.size() - 1) 
            index = (int)boxes_.size() - 1;

        if (index < 0)
            index = 0;

        return index;
    }

    // the required amount of boxes in the space
    std::vector<Box<Entity, cocos2d::OBB, cocos2d::AABB> > boxes_;

    // this is used to store any valid neighbors when an agent searches its neighboring space
    std::vector<Entity*> neighbors_;

    // this iterator will be used by the methods next and begin to traverse
    // through the above vector of neighbors
    typename std::vector<Entity*>::iterator cur_neighbor_;

    // the number of boxes the space is going to be divided up into
    int num_boxes_x_;
    int num_boxes_y_;
    int num_boxes_z_;

    float space_size_x_;
    float space_size_y_;
    float space_size_z_;

    float box_size_x_;
    float box_size_y_;
    float box_size_z_;

    cocos2d::Vec3 space_origin_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_SPACE_PARTITION_H_