/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  graph_node.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-13
  @ description:  offer graph node functions.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_GRAPH_NODE_H_
#define CITY_HUNTER_SRC_GRAPH_NODE_H_

#include "graph_constants.h"

namespace gamer
{

namespace graph
{

class GraphNode
{
public:
    GraphNode() 
        :index_(gamer::graph::INVALID_NODE_INDEX) 
        ,enabled_(true)
    {
    }

    GraphNode(int index) 
        :index_(index)
        ,enabled_(true)
    {
    }

    virtual ~GraphNode() {}

    inline int index() const { return index_; }

    inline void set_index(int index) { index_ = index; }

    inline bool enabled() const { return enabled_; }

    inline void set_enabled(bool enabled) { enabled_ = enabled; }

protected:
    int index_; // id of graph node, valid value should >= 0
    bool enabled_;
};

template<typename PositionType, typename ExtraInfo = void*>
class NavGraphNode : public GraphNode
{
public:
    typedef PositionType Position;
    
    NavGraphNode() 
        :extra_info_(ExtraInfo()) 
    {
    }

    NavGraphNode(int index, PositionType pos)
        :GraphNode(index)
        ,position_(pos)
        ,extra_info_(ExtraInfo())
        ,contains_game_obj_(false)
    {
    }

    virtual ~NavGraphNode() {};

    inline Position position() const { return position_; }

    inline void set_position(PositionType pos) { position_ = pos; }

    inline ExtraInfo extra_info() const { return extra_info_; }

    inline void set_extra_info(ExtraInfo info) { extra_info_ = info; }

    inline void set_contains_game_obj(bool contains) 
    { 
        contains_game_obj_ = contains; 

        // set the enabling for all edges of this node 
        //auto graph = PathFinder::getInstance()->graph();
        //if (nullptr != graph)
        //{
        //    Graph::EdgeIterator edge_iter(graph, index_);
        //
        //    for (Graph::Edge* edge = edge_iter.begin();
        //        !edge_iter.end(); 
        //        edge = edge_iter.next())
        //    {
        //        edge->set_enabled(contains);
        //    }  
        //}
    }

    inline bool contains_game_obj() { return contains_game_obj_; }

protected:
    PositionType position_;
    ExtraInfo extra_info_;
    bool contains_game_obj_; // weather these is a game object on the node, useful for collision checking
};

} // namespace graph

} // namespace gamer

#endif // CITY_HUNTER_SRC_GRAPH_NODE_H_
