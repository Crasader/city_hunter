/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  graph_typedef.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-15
  @ description:  define common graph type.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_GRAPH_TYPEDEF_H_
#define CITY_HUNTER_SRC_GRAPH_TYPEDEF_H_

#include "cocos/3d/CCAABB.h"
#include "cocos/3d/CCOBB.h"
#include "cocos/3d/CCSprite3D.h"
#include "cocos/math/Vec3.h"

#include "actor_typedef.h"
#include "a_star_heuristic_policies.h"
#include "graph.h"
#include "graph_algorithms.h"
#include "graph_edge.h"
#include "graph_node.h"
#include "space_partition.h"

//namespace cocos2d
//{
//    
//class Sprite3D;
//class Vec3;
//class OBB;
//class AABB;
//    
//}

namespace gamer
{
    
namespace graph
{

typedef NavGraphNode<cocos2d::Vec3> NavGraphNode3D;
typedef SparseGraph<NavGraphNode3D, graph::NavGraphEdge> SparseGraph3D;
typedef AStar<SparseGraph3D, graph::HeuristicEuclid> AStarSearch;

typedef BoxSpacePartition<gamer::ActorType, cocos2d::Vec3, cocos2d::OBB, cocos2d::AABB> SpacePartition3D;

typedef std::list<int> PathNodes;    
    
typedef struct CellType
{
    int w;
    int h;
} Cell;

typedef struct SizeType
{
    float x;
    float y;
    float z;
} Size;
    
} // namespace graph
    
} // namespace gamer

#endif // CITY_HUNTER_SRC_GRAPH_TYPEDEF_H_