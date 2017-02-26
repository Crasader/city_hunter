/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  path_finder.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-11-01
  @ description:  
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_PATH_FINDER_H_
#define CITY_HUNTER_SRC_PATH_FINDER_H_

#include <list>

#include "cocos2d.h"
#include "graph_typedef.h"

namespace gamer
{

class Command;
class Event;

class PathFinder
{
public:
    ~PathFinder();

    static PathFinder* getInstance();

    static void destoryInstance();

    bool init();

    graph::AStarSearch::PathNodes doAStarSearch(int source, int target);

    inline void set_graph(graph::SparseGraph3D* sparse_graph) { sparse_graph_ = sparse_graph; }

    inline graph::SparseGraph3D* graph() const { return sparse_graph_; }

    inline void set_path(graph::AStarSearch::PathNodes& path) { path_ = path; }

    inline graph::AStarSearch::PathNodes path() const { return path_; }

private:
    PathFinder();

    bool initListeners();

    //void onCommandDrawPath(gamer::Event* event);   
    void onCommandDrawPath(gamer::Command* event);   

    graph::SparseGraph3D* sparse_graph_;

    graph::AStarSearch::PathNodes path_; // the path that store node indexes
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_PATH_FINDER_H_