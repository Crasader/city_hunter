/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  a_star_heuristic_policies.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-15
  @ description:  offer heuristic policies for A* algorithms.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_A_STAR_HEURISTIC_POLICIES_H_
#define CITY_HUNTER_SRC_A_STAR_HEURISTIC_POLICIES_H_

namespace gamer
{

namespace graph
{

//the euclidian heuristic (straight-line distance)
class HeuristicEuclid 
{
public:
    HeuristicEuclid() {}

    // calculate the straight line distance from node nd1 to node nd2
    template <class Graph>
    static double calculate(const Graph& graph, int node1, int node2)
    {
        // TODO : if the "position" type is not the "Vec2" or the "Vec3" of cocos2d-x, 
        // modify the below code, make sure that "position" type include a "distance" function 
        // that accept a "position" type param

        typename Graph::NodeType n1 = graph.getNode(node1);
        typename Graph::NodeType n2 = graph.getNode(node2);

        return n1.position().distance(n2.position());

        // return graph.getNode(node1).position().distance(graph.getNode(node2).position());
    }
};

// you can use this class to turn the A* algorithm into Dijkstra's search.
// this is because Dijkstra's is equivalent to an A* search using a heuristic
// value that is always equal to zero.
class HeuristicDijkstra 
{
public:
    template <class Graph>
    static float calculate(const Graph& graph, int nd1, int nd2)
    {
        return 0;
    }
};

} // namespace graph

} // namespace gamer

#endif // CITY_HUNTER_SRC_A_STAR_HEURISTIC_POLICIES_H_