/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  utils_graph.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-19
  @ description:  offer some useful functions about graph.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_UTILS_GRAPH_H_
#define CITY_HUNTER_SRC_UTILS_GRAPH_H_

#include <list>

#include "cocos2d.h"
#include "cocos/3d/MyDrawNode3D.h"

#include "scene_manager.h"
#include "typedef.h"

namespace gamer
{

namespace utils_graph
{

// returns true if x,y is a 2d graph node that is positioned in a grid layout.
inline bool isNeighborValid(int x, int y, int num_cells_x, int num_cells_y)
{
    return !((x < 0) || (x >= num_cells_x) || (y < 0) || (y >= num_cells_y));
}

// use to add he eight neighbor edges of a 2d graph node that is positioned in a grid layout.
template <typename Graph>
void addAllEdgesToNode(Graph& graph,
                       int row,
                       int col,
                       int num_cells_x,
                       int num_cells_y)
{   
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            int node_x = col + j;
            int node_y = row + i;

            // skip if it's self node
            if ((0 == i) && (0 == j)) 
                continue;

            // check to see if this is a valid neighbor
            if (!isNeighborValid(node_x, node_y, num_cells_x, num_cells_y))
                continue;

            // calculate the distance to this node
            auto node_pos     = graph.getNode(row * num_cells_x + col).position();
            auto neighbor_pos = graph.getNode(node_y * num_cells_x + node_x).position();
            
            float dist = node_pos.distance(neighbor_pos);

            // this neighbor is ok so it can be added
            typename Graph::EdgeType new_edge(row * num_cells_x + col,
                                     node_y * num_cells_x + node_x,
                                     dist);
            graph.addEdge(new_edge);

            // if graph is not a digraph then an edge needs to be added going in the other direction
            if (!graph.is_digraph())
            {
                typename Graph::EdgeType new_edge(node_y * num_cells_x + node_x,
                                         row * num_cells_x + col,
                                         dist);
                graph.addEdge(new_edge);
            }
            
        }
    }
}

//  given a cost value and an index to a valid node this function examines 
//  all a node's edges, calculates their length, and multiplies
//  the value with the weight. Useful for setting terrain costs.
template <class Graph>
void weightNavGraphNodeEdges(Graph& graph, int node, float weight)
{
    // make sure the node is present
    assert(true == graph.isNodePresent(node));

    // set the cost for each edge
    typename Graph::ConstEdgeIterator const_edge_iter(graph, node);
    //for (const Graph::EdgeType* edge = const_edge_iter.begin();
    for (auto edge = const_edge_iter.begin();
         !const_edge_iter.end();
         edge = const_edge_iter.next())
    {
        // calculate the distance between nodes
        // TODO : if the "position" type is not the "Vec2" or the "Vec3" of cocos2d-x, 
        // modify the below code, make sure that "position" type include a "distance" function 
        // that accept a "position" type param
        typename Graph::NodeType node_from = graph.getNode(edge->node_from());
        typename Graph::NodeType node_to   = graph.getNode(edge->node_to());
        float dist = node_from.position().distance(node_from.position());

        // set the cost of this edge
        graph.setEdgeCost(edge->node_from(), edge->node_to(), dist * weight);

        // if not a digraph, set the cost of the parallel edge to be the same
        if (!graph.is_digraph())
        {      
            graph.setEdgeCost(edge->node_to(), edge->node_from(), dist * weight);
        }
    }
}

// draw the path with given path nodes, graph, painter(cocos2d's DrawNode3D), color(cocos2d::Color4F)
template <typename Graph, 
          typename Painter, 
          typename Color>
void drawPath(std::list<int>& path_nodes, 
              const Graph& graph, 
              Painter& painter, 
              const Color& color)
{
    if ( !path_nodes.empty() )
    {
        //painter->clear();

        auto cur = path_nodes.begin();
        auto next = cur; 
        ++next;

        for (; next != path_nodes.end(); ++cur, ++next)
        {
            painter.drawLine(graph.getNode(*cur).position(), 
                             graph.getNode(*next).position(), 
                             color);
        }
    }
}

inline int getNodeIndexByPos(const cocos2d::Vec3& pos)
{
    auto space_ori = SceneManager::getInstance()->getSpaceOriginOfScene();
    auto cell      = SceneManager::getInstance()->getCellOfScene();
    auto cell_num  = SceneManager::getInstance()->getCellNumOfScene();
    
    int complete_row   = (space_ori.z - pos.z - cell.h / 2.0) / cell.h;
    int incpmplete_row = (pos.x - space_ori.x - cell.w / 2.0) / cell.w;
    
    int index = complete_row * cell_num.x + incpmplete_row;
    if (index < 0)
    {
        index = 0;
    }
    
    return index;
}
    
} // namespace utils_graph

} // namespace gamer

#endif // CITY_HUNTER_SRC_UTILS_GRAPH_H_