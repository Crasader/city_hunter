/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  graph_edge.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-13
  @ description:  offer graph edge functions.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_GRAPH_EDGE_H_
#define CITY_HUNTER_SRC_GRAPH_EDGE_H_

#include "graph_constants.h" 

namespace gamer
{

namespace graph
{

class GraphEdge
{
public:
    GraphEdge()
        :node_from_(gamer::graph::INVALID_NODE_INDEX)
        ,node_to_(gamer::graph::INVALID_NODE_INDEX)
        ,cost_(1.0f)
        ,enabled_(true)
    {
    }

    GraphEdge(int node_from, int node_to, float cost)
        :node_from_(node_from)
        ,node_to_(node_to)
        ,cost_(cost)
    {
    }

    GraphEdge(int node_from, int node_to)
        :node_from_(node_from)
        ,node_to_(node_to)
        ,cost_(1.0f)
    {
    }

    virtual ~GraphEdge() {}

    inline bool operator==(const GraphEdge& graph_edge) const
    {
        return graph_edge.node_from_ == this->node_from_ &&
               graph_edge.node_to_   == this->node_to_   &&
               graph_edge.cost_      == this->cost_;
    }

    inline bool operator!=(const GraphEdge& graph_edge) { return !(*this == graph_edge); }

    inline int node_from() const { return node_from_; }

    inline void set_node_from(int node_index) { node_from_ = node_index; }

    inline int node_to() const { return node_to_; }

    inline void set_node_to(int node_index) { node_to_ = node_index; }

    inline float cost() const { return cost_; }

    inline void set_cost(float cost) { cost_ = cost; }

    inline bool enabled() const { return enabled_; }

    inline void set_enabled(bool enabled) { enabled_ = enabled; }

protected:
    int node_from_; // index of 'node from' for this edge

    int node_to_;   // index of 'node to' for this edge

    float cost_;    // cost for cross this edge

    bool enabled_;
};

class NavGraphEdge : public GraphEdge
{
public:
    //examples of typical flags
    enum NavGraphEdgeTypes
    {
        NORMAL            = 0,
        SWIM              = 1 << 0,
        CRAWL             = 1 << 1,
        CREEP             = 1 << 3,
        JUMP              = 1 << 3,
        FLY               = 1 << 4,
        GRAPPLE           = 1 << 5,
        GOES_THROUGH_DOOR = 1 << 6
    };

    NavGraphEdge(int from, int to, float cost, int flags = 0, int id = -1)
        :GraphEdge(from, to, cost)
        ,flags_(flags)
        ,id_of_intersecting_entity_(id)
    {
    } 

    inline int flags() const { return flags_; }

    inline void set_flags(int flags) { flags_ = flags; }

    inline int id_of_intersecting_entity() const { return id_of_intersecting_entity_; }

    inline void set_id_of_intersecting_entity(int id) { id_of_intersecting_entity_ = id; }

protected:
    int flags_;

    // if this edge intersects with an object (such as a door or lift), then
    // this is that object's ID. 
    int id_of_intersecting_entity_;
};

} // namespace graph

}

#endif // CITY_HUNTER_SRC_GRAPH_EDGE_H_