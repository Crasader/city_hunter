/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  path_finder.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-11-01
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "path_finder.h"

#include "command.h"
#include "command_constants.h"
#include "command_listener.h"
#include "command_manager.h"
#include "macros.h"

namespace gamer
{

PathFinder::PathFinder() : sparse_graph_(nullptr)
{

}

PathFinder::~PathFinder()
{

}

PathFinder* PathFinder::getInstance()
{
    static PathFinder* path_finder = nullptr;
    if (nullptr == path_finder)
    {
        path_finder = new PathFinder();
        if ( !path_finder->initListeners() )
        {
            SAFE_DELETE(path_finder); 
        }
    }
    return path_finder;
}

void PathFinder::destoryInstance()
{
    PathFinder* path_finder = PathFinder::getInstance();
    SAFE_DELETE(path_finder);
}

bool PathFinder::init()
{
    return true;
}

graph::AStarSearch::PathNodes PathFinder::doAStarSearch(int source, int target)
{
    if (nullptr == sparse_graph_)
    {
        graph::AStarSearch::PathNodes path_nodes;
        return path_nodes;
    }

    graph::AStarSearch astar(*sparse_graph_, source, target);
    return astar.getPathToTarget();
}

bool PathFinder::initListeners()
{
    auto listener = gamer::CommandListener::create(
        CommandIDs::CMD_DRAW_PATH, 
        std::bind(&PathFinder::onCommandDrawPath, this, std::placeholders::_1),
        "PathFinder::onCommandDrawPath", 
        1);
    CommandManager::getInstance()->addCmdListener(listener);

    return true;
}

void PathFinder::onCommandDrawPath(gamer::Command* cmd)
{
   
}

} // namespace gamer
