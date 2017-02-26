/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  graoh.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-13
  @ description:  offer graph functions, such as navigation graph functions.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_GRAPH_H_
#define CITY_HUNTER_SRC_GRAPH_H_

#include <cassert>
#include <fstream>
#include <list>
#include <string>
#include <vector>

#include "graph_constants.h"

namespace gamer
{

namespace graph
{

template<typename GraphNode, typename GraphEdge>
class SparseGraph
{
public:
    typedef GraphNode NodeType;
    typedef GraphEdge EdgeType;

    typedef std::vector<GraphNode> NodeVector;
    typedef std::list<GraphEdge> EdgeList;
    typedef std::vector<EdgeList> EdgeListVector;

    // non const class used to iterate through the nodes in the graph.
    class NodeIterator
    {
    public:
        NodeIterator(SparseGraph<GraphNode, GraphEdge> &graph) : graph_(graph)
        {
            cur_node_ = graph_.nodes_.begin();
        }

        GraphNode* begin()
        {      
            cur_node_ = graph_.nodes_.begin();

            getNextValidNode(cur_node_);

            return &(*cur_node_);
        }

        GraphNode* next()
        {
            ++cur_node_;

            if (end()) 
            {
                return nullptr;
            }

            getNextValidNode(cur_node_);

            return &(*cur_node_);
        }

        bool end()
        {
            return cur_node_ == graph_.nodes_.end();
        }

    private:
        // if a graph node is removed, it is not removed from the 
        // vector of nodes (because that would mean changing all the indices of 
        // all the nodes that have a higher index). This method takes a node
        // iterator as a parameter and assigns the next valid element to it.
        void getNextValidNode(typename NodeVector::iterator& it)
        {
            if (cur_node_ == graph_.nodes_.end() || it->index() != gamer::graph::INVALID_NODE_INDEX) 
                return;

            while ((it->index() == gamer::graph::INVALID_NODE_INDEX))
            {
                ++it;

                if (cur_node_ == graph_.nodes_.end()) 
                {
                    break;
                }
            }
        }

        typename NodeVector::iterator cur_node_;

        SparseGraph<GraphNode, GraphEdge>& graph_;
    };

    // const class used to iterate through the nodes in the graph.
    class ConstNodeIterator
    {
    public:
        ConstNodeIterator(const SparseGraph<GraphNode, GraphEdge> &graph) : graph_(graph)
        {
            cur_node_ = graph_.nodes_.begin();
        }

        const GraphNode* begin()
        {      
            cur_node_ = graph_.nodes_.begin();

            getNextValidNode(cur_node_);

            return &(*cur_node_);
        }

        const GraphNode* next()
        {
            ++cur_node_;

            if (end())
            {
                return nullptr;
            }
            else
            {
                getNextValidNode(cur_node_);

                return &(*cur_node_);
            }
        }

        bool end()
        {
            return (cur_node_ == graph_.nodes_.end());
        }

    private:
        // if a graph node is removed or switched off, it is not removed from the 
        // vector of nodes (because that would mean changing all the indices of 
        // all the nodes that have a higher index. This method takes a node
        // iterator as a parameter and assigns the next valid element to it.
        void getNextValidNode(typename NodeVector::const_iterator& it)
        {
            if (cur_node_ == graph_.nodes_.end() || it->index() != graph::INVALID_NODE_INDEX) 
                return;

            while ((it->index() == graph::INVALID_NODE_INDEX))
            {
                ++it;

                if (cur_node_ == graph_.nodes_.end()) 
                {
                    break;
                }
            }
        }

        typename NodeVector::const_iterator cur_node_;

        const SparseGraph<GraphNode, GraphEdge>& graph_;
    };

    // non const class used to iterate through all the edges connected to a specific node. 
    class EdgeIterator
    {
    public:
        EdgeIterator(SparseGraph<GraphNode, GraphEdge>& graph, int node) 
            :graph_(graph)
            ,node_index_(node)
        {
            // we don't need to check for an invalid node index since if the node is
            // invalid there will be no associated edges            

            cur_edge_ = graph_.edges_[node_index_].begin();
        }

        GraphEdge* begin()
        {        
            cur_edge_ = graph_.edges_[node_index_].begin();

            return &(*cur_edge_);
        }

        GraphEdge* next()
        {
            ++cur_edge_;

            if (end()) 
            { 
                return nullptr;
            }

            return &(*cur_edge_);
        }

        //return true if we are at the end of the edge list
        bool end()
        {
            return cur_edge_ == graph_.edges_[node_index_].end();
        }

    private:                                                      
        typename EdgeList::iterator cur_edge_;

        SparseGraph<GraphNode, GraphEdge>& graph_;

        const int node_index_;
    };

    // const class used to iterate through all the edges connected to a specific node. 
    class ConstEdgeIterator
    {
    public:
        ConstEdgeIterator(const SparseGraph<GraphNode, GraphEdge>& graph, int node) 
            :graph_(graph)
            ,node_index_(node)
        {
            // we don't need to check for an invalid node index since if the node is
            // invalid there will be no associated edges.

            cur_edge_ = graph_.edges_[node_index_].begin();
        }

        const GraphEdge* begin()
        {        
            cur_edge_ = graph_.edges_[node_index_].begin();

            if (end()) 
            {
                return 0;
            }

            return &(*cur_edge_);
        }

        const GraphEdge* next()
        {
            ++cur_edge_;

            if(end())
            {
                return nullptr;
            }
            else
            {
                return &(*cur_edge_);
            }
        }

        //return true if we are at the end of the edge list
        bool end()
        {
            return cur_edge_ == graph_.edges_[node_index_].end();
        }

    private:                                                               
        typename EdgeList::const_iterator cur_edge_;

        const SparseGraph<GraphNode, GraphEdge>& graph_;

        const int node_index_;
    };

    SparseGraph(bool is_digraph) 
        :is_digraph_(is_digraph)
        ,next_node_index_(0)
    {
    }

    // TODO : const func and not const func use shared code
    const GraphNode& getNode(int index) const
    {
        assert((index < (int)nodes_.size()) &&
               (index >=0 )                  &&
               "[SparseGraph::getNode] : invalid index!");
        return nodes_[index];
    }

    GraphNode& getNode(int index)
    {
        assert((index < (int)nodes_.size()) &&
               (index >=0)                  &&
               "[SparseGraph::getNode] : invalid index!");
        return nodes_[index];
    }

    // TODO : const func and not const func use shared code
    const GraphEdge& getEdge(int node_from, int node_to) const
    {
        assert((node_from < nodes_.size()) &&
               (node_from >= 0)            &&
               nodes_[node_from].index() != gamer::graph::INVALID_NODE_INDEX &&
               "[SparseGraph::getEdge] : invalid 'node_from' index!");

        assert((node_to < nodes_.size()) &&
               (node_to >= 0)            &&
               nodes_[node_to].index() != gamer::graph::INVALID_NODE_INDEX &&
               "[SparseGraph::getEdge] : invalid 'node_to' index!");

        for (auto it = edges_[node_from].begin(); it != edges_[node_from].end(); ++it)
        {
            if (it->node_to() == node_to) 
                return *it;
        }

        assert(0 && "[SparseGraph::getEdge] : edge does not exist!");
    }

    GraphEdge& getEdge(int node_from, int node_to) 
    {
        assert((node_from < nodes_.size()) &&
               (node_from >= 0)            &&
               nodes_[node_from].index() != gamer::graph::INVALID_NODE_INDEX &&
               "[SparseGraph::getEdge] : invalid 'node_from' index!");

        assert((node_to < nodes_.size()) &&
               (node_to >=0)            &&
               nodes_[node_to].index() != gamer::graph::INVALID_NODE_INDEX &&
               "[SparseGraph::getEdge] : invalid 'node_to' index!");

        for (auto it = edges_[node_from].begin(); it != edges_[node_from].end(); ++it)
        {
            if (it->node_to() == node_to) 
                return *it;
        }

        assert(0 && "[SparseGraph::getEdge] : edge does not exist!");
    }

    inline int getNextFreeNodeIndex() const { return next_node_index_; }

    int addNode(GraphNode node)
    {
        if (node.index() < (int)nodes_.size())
        {
            // make sure the client is not trying to add a node with the same ID as a currently active node
            assert(nodes_[node.index()].index() == gamer::graph::INVALID_NODE_INDEX &&
                   "[SparseGraph::addNode] : attempting to add a node with a duplicate ID!");

            nodes_[node.index()] = node;

            return next_node_index_;
        }
        else
        {
            // make sure the new node has been indexed correctly
            assert(node.index() == next_node_index_ && "[SparseGraph::addNode] : invalid index!");

            nodes_.push_back(node);
            edges_.push_back(EdgeList());

            return next_node_index_++;
        }
    }

    void removeNode(int node_index)
    {
        assert(node_index < (int)nodes_.size() && "[SparseGraph::RemoveNode] : invalid node index!");

        // set the node's index to gamer::graph::INVALID_NODE_INDEX, that means the node has been removed
        nodes_[node_index].set_index(gamer::graph::INVALID_NODE_INDEX);

        // if the graph is not directed remove all edges leading to this node and then clear the edges leading from the node
        if (!is_digraph_)
        {    
            // visit each neighbor and erase any edges leading to this node
            for (auto it = edges_[node_index].begin(); 
                 it != edges_[node_index].end();
                 ++it)
            {
                for (auto iter = edges_[it->node_to()].begin();
                     iter != edges_[it->node_to()].end();
                     ++iter)
                {
                    if (iter->node_to() == node_index)
                    {
                        iter = edges_[it->node_to()].erase(iter);
                        break;
                    }
                }
            }

            // finally, clear the node's edges
            edges_[node_index].clear();
        }
        // if a digraph remove the edges the slow way
        else
        {
            cullInvalidEdges();
        }
    }

    void addEdge(GraphEdge edge)
    {
        // make sure the node_from and node_to exist within the graph 
        assert((edge.node_from() < next_node_index_) && 
               (edge.node_to() < next_node_index_)   &&
               "[SparseGraph::addEdge] : invalid node index!");

        // make sure both nodes are active before adding the edge
        if ((nodes_[edge.node_from()].index() != gamer::graph::INVALID_NODE_INDEX) && 
            (nodes_[edge.node_to()].index() != gamer::graph::INVALID_NODE_INDEX))
        {
            // add the edge, first making sure it is unique
            if (uniqueEdge(edge.node_from(), edge.node_to()))
            {
                edges_[edge.node_from()].push_back(edge);
            }

            // if the graph is undirected we must add another connection in the opposite direction
            if (!is_digraph_)
            {
                // check to make sure the edge is unique before adding
                if (uniqueEdge(edge.node_to(), edge.node_from()))
                {
                    GraphEdge new_edge = edge;

                    new_edge.set_node_to(edge.node_from());
                    new_edge.set_node_from(edge.node_to());

                    edges_[edge.node_to()].push_back(new_edge);
                }
            }
        }
    }

    void removeEdge(int node_from, int node_to)
    {
        assert((node_from < (int)nodes_.size()) && 
               (node_to < (int)nodes_.size())   &&
               "[SparseGraph::removeEdge] : invalid node index!");

        typename EdgeList::iterator egde;

        //if (!is_digraph_)
        //{
        //    for (egde = edges_[node_to].begin();
        //         egde != edges_[node_to].end();
        //         ++egde)
        //    {
        //        if (egde->node_to() == node_from)
        //        {
        //            egde = edges_[node_to].erase(egde);
        //            break;
        //        }
        //    }
        //}

        for (egde = edges_[node_from].begin();
             egde != edges_[node_from].end();
             ++egde)
        {
            if (egde->node_to() == node_to)
            {
                egde = edges_[node_from].erase(egde);
                break;
            }
        }

        if (!is_digraph_)
        {
            for (egde = edges_[node_to].begin();
                egde != edges_[node_to].end();
                ++egde)
            {
                if (egde->node_to() == node_from)
                {
                    egde = edges_[node_to].erase(egde);
                    break;
                }
            }
        }
    }

    void removeAllEdges()
    {
        for (auto edge = edges_.begin(); edge != edges_.end(); ++edge)
        {
            edge->clear();
        }
    }

    void setEdgeCost(int node_from, int node_to, float cost)
    {
        // make sure the nodes given are valid
        assert((node_from < (int)nodes_.size()) && 
               (node_to < (int)nodes_.size())   &&
               "[SparseGraph::setEdgeCost] : invalid index!");

        // visit each neighbor and erase any edges leading to this node
        for (auto edge = edges_[node_from].begin(); 
             edge != edges_[node_from].end();
             ++edge)
        {
            if (edge->node_to() == node_to)
            {
                edge->set_cost(cost);
                break;
            }
        }
    }

    inline int num_nodes() const { return (int)nodes_.size(); }
    
    // TODO : cache the num to improve the performance
    int getNumOfActiveNodes() const
    {
        int count = 0;

        for (int i = 0; i < nodes_.size(); ++i) 
        {
            if (nodes_[i].index() != gamer::graph::INVALID_NODE_INDEX) 
            {
                ++count;
            }
        }

        return count;
    }

    int getNumOfEdges()const
    {
        int total = 0;

        for (auto edge_list = edges_.begin();
             edge_list != edges_.end();
             ++edge_list)
        {
            total += edge_list->size();
        }

        return total;
    }

    inline bool is_digraph() const { return is_digraph_; }

    inline bool empty() const { return nodes_.empty(); }

    bool isNodePresent(int node_index) const
    {
        if ((node_index >= (int)nodes_.size() || 
            (nodes_[node_index].index() == gamer::graph::INVALID_NODE_INDEX)))
        {
            return false;
        }

        return true;
    }

    bool isEdgePresent(int node_from, int node_to) const
    {
        if (isNodePresent(node_from) && isNodePresent(node_to))
        {
            for (auto edge = edges_[node_from].begin();
                 edge != edges_[node_from].end();
                 ++edge)
            {
                if (edge->node_to() == node_to) 
                {
                    return true;
                }
            }

            //return false;
        }
        
        return false;
    }

    bool load(std::string& file_name)
    {
        // open file and make sure it's valid
        assert(file_name.empty() && "[SparseGraph::load] : invalid file name!");

        std::ifstream in(file_name.c_str());

        if (!in)
        {
            //throw std::runtime_error("Cannot open file : " + file_name);
            return false;
        }

        return load(in);
    }

    bool load(std::ifstream& stream)
    {
        clear();

        // get the number of nodes and read them in
        int num_nodes, num_edges;

        stream >> num_nodes;

        for (int n = 0; n < num_nodes; ++n)
        {
            GraphNode new_node(stream);

            // when editing graphs it's possible to end up with a situation where some
            // of the nodes have been invalidated (their id's set to invalid_node_index). 
            // therefore when a node of index invalid_node_index is encountered, it must still be added.
            if (new_node.index() != gamer::graph::INVALID_NODE_INDEX)
            {
                addNode(new_node);
            }
            else
            {
                nodes_.push_back(new_node);

                // make sure an edge list is added for each node
                edges_.push_back(EdgeList());

                ++next_node_index_;
            }
        }

        // now add the edges
        stream >> num_edges;
        for (int e = 0; e < num_edges; ++e)
        {
            GraphEdge next_edge(stream);

            addEdge(next_edge);
        }

        return true;
    }

    bool save(std::string& file_name) const
    {
        // open the file and make sure it's valid
        assert(file_name.empty() && "[SparseGraph::save] : invalid file name!");
        
        std::ofstream out(file_name);

        if (!out)
        {
            //throw std::runtime_error("Cannot open file: " + std::string(FileName));
            return false;
        }

        return save(out);
    }

    bool save(std::ofstream& stream) const
    {
        // save the number of nodes
        stream << nodes_.size() << std::endl;

        // iterate through the graph nodes and save them
        for (auto node = nodes_.begin(); node != nodes_.end(); ++node)
        {
            stream << *node;
        }

        // save the number of edges
        stream << getNumOfEdges() << std::endl;

        // iterate through the edges and save them
        for (int i = 0, n = (int)nodes_.size(); i < n; ++i)
        {
            for (auto edge = edges_[i].begin();
                 edge != edges_[i].end(); 
                 ++edge)
            {
                stream << *edge;
            }  
        }

        return true;
    }

    void clear()
    { 
        next_node_index_ = 0; 
        nodes_.clear(); 
        edges_.clear(); // ? TODO : remove all edges before doing this
    }
    
private:
    void cullInvalidEdges()
    {
        for (auto edge_list = edges_.begin(); 
             edge_list != edges_.end(); 
             ++edge_list)
        {
            for (auto edge = (*edge_list).begin(); 
                 edge != (*edge_list).end(); 
                 ++edge)
            {
                if (nodes_[edge->node_to()].index() == gamer::graph::INVALID_NODE_INDEX || 
                    nodes_[edge->node_from()].index() == gamer::graph::INVALID_NODE_INDEX)
                {
                    edge = (*edge_list).erase(edge);
                }
            }
        }
    }

    bool uniqueEdge(int node_from, int node_to) const
    {
        for (auto edge = edges_[node_from].begin();
             edge != edges_[node_from].end();
             ++edge)
        {
            if (edge->node_to() == node_to)
            {
                return false;
            }
        }

        return true;
    }

    NodeVector nodes_;
    EdgeListVector edges_;
    bool is_digraph_;
    int next_node_index_;

    friend class NodeIterator;
    friend class EdgeIterator;
    friend class ConstNodeIterator;
    friend class ConstEdgeIterator;    
};

} // namespace graph

} // namespace gamer

#endif // CITY_HUNTER_SRC_GRAPH_H_