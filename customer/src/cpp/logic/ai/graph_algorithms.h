/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  graph_algorithms.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-14
  @ description:  offer common graph algorithms.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_GRAPH_ALGORITHMS_H_
#define CITY_HUNTER_SRC_GRAPH_ALGORITHMS_H_

#include <cassert>
#include <vector>

namespace gamer
{

namespace graph
{

    
    template<class KeyType>
    class IndexedPriorityQueueLow
    {
    public:
        // you must pass the constructor a reference to the std::vector the PQ
        // will be indexing into and the maximum size of the queue.
        IndexedPriorityQueueLow(std::vector<KeyType>& keys, int max_size)
        :keys_(keys)
        ,max_size_(max_size)
        ,size_(0)
        {
            heap_.assign(max_size + 1, 0);
            inv_heap_.assign(max_size + 1, 0);
        }
        
        inline bool empty() const { return 0 == size_; }
        
        // to insert an item into the queue it gets added to the end of the heap
        // and then the heap is reordered from the bottom up.
        void insert(const int idx)
        {
            assert(idx >= 0);
            assert(size_ + 1 <= max_size_);
            
            ++size_;
            
            heap_[size_] = idx;
            
            inv_heap_[idx] = size_;
            
            reorderUpwards(size_);
        }
        
        // to get the min item the first element is exchanged with the lowest
        // in the heap and then the heap is reordered from the top down.
        int pop()
        {
            swap(1, size_);
            
            reorderDownwards(1, size_-1);
            
            return heap_[size_--];
        }
        
        // if the value of one of the client key's changes then call this with
        // the key's index to adjust the queue accordingly
        void changePriority(const int idx)
        {
            reorderUpwards(inv_heap_[idx]);
        }
        
    private:
        void swap(int a, int b)
        {
            int temp = heap_[a];
            heap_[a] = heap_[b];
            heap_[b] = temp;
            
            // change the handles too
            inv_heap_[heap_[a]] = a; inv_heap_[heap_[b]] = b;
        }
        
        void reorderUpwards(int nd)
        {
            // move up the heap swapping the elements until the heap is ordered
            while ( (nd>1) && (keys_[heap_[nd/2]] > keys_[heap_[nd]]) )
            {
                swap(nd/2, nd);
                nd /= 2;
            }
        }
        
        void reorderDownwards(int nd, int HeapSize)
        {
            // move down the heap from node nd swapping the elements until
            // the heap is reordered
            while (2*nd <= HeapSize)
            {
                int child = 2 * nd;
                
                // set child to smaller of nd's two children
                if ((child < HeapSize) && (keys_[heap_[child]] > keys_[heap_[child+1]]))
                {
                    ++child;
                }
                
                // if this nd is larger than its child, swap
                if (keys_[heap_[nd]] > keys_[heap_[child]])
                {
                    swap(child, nd);
                    
                    // move the current node down the tree
                    nd = child;
                }
                else
                {
                    break;
                }
            }
        }
        
        std::vector<KeyType>& keys_;
        
        std::vector<int> heap_;
        
        std::vector<int> inv_heap_;
        
        int size_;
        int max_size_;
    };
    
template <typename Graph, typename Heuristic>
class AStar
{
public:
    // create a typedef for the edge type used by the graph
    typedef typename Graph::EdgeType Edge;

    typedef std::list<int> PathNodes;

    AStar(Graph &graph, int source, int target)
        :graph_(graph)
        ,shortest_path_(graph.num_nodes())                            
        ,search_frontier_(graph.num_nodes())
        ,costs_of_g_(graph.num_nodes(), 0.0)
        ,costs_of_f_(graph.num_nodes(), 0.0)
        ,source_(source)
        ,target_(target)
    {
        search();   
    }

    // returns the vector of edges that the algorithm has examined(shortest path tree)
    inline std::vector<const Edge*> shortest_path() const { return shortest_path_; }

    // returns the total cost to the target
    inline float cost_to_target() const { return costs_of_g_[target_]; }

    // returns a vector of node indexes that comprise the shortest path
    // from the source to the target
    PathNodes getPathToTarget() const
    {
        PathNodes path;

        // just return an empty path if no target or no path found
        if (target_ < 0)  
            return path;    

        int node = target_;

        path.push_front(node);

        //while ((node != source_) && (shortest_path_[node] != 0))
        while ((node != source_) && (nullptr != shortest_path_[node]))
        {
            node = shortest_path_[node]->node_from();

            path.push_front(node);
        }

        return path;
    }

    inline void set_source(int source) { source_ = source; }

    inline void set_target(int target) { target_ = target; }

    // the A* search algorithm
    void search()
    {
        // create an indexed priority queue of nodes. The nodes with the
        // lowest overall F cost (G+H) are positioned at the front.
        IndexedPriorityQueueLow<float> pq(costs_of_f_, graph_.num_nodes());
        //std::priority_queue<float, std::vector<float>, greater<float> > pq(graph_.num_nodes())

        // put the source node on the queue
        pq.insert(source_);

        // while the queue is not empty
        while(!pq.empty())
        {
            // get lowest cost node from the queue
            int next_closest_node = pq.pop();

            // move this node from the frontier to the spanning tree
            shortest_path_[next_closest_node] = search_frontier_[next_closest_node];

            // if the target has been found, then exit
            if (next_closest_node == target_) 
                return;

            // if the node is disabled, ignore it
            if ( !graph_.getNode(next_closest_node).enabled() )
                continue;

            // now to test all the edges attached to this node
            typename Graph::ConstEdgeIterator const_edge_iter(graph_, next_closest_node);

            for (const Edge* edge = const_edge_iter.begin();
                 !const_edge_iter.end();
                 edge = const_edge_iter.next())
            {
                // calculate the heuristic cost from this node to the target (H)                       
                float h_cost = Heuristic::calculate(graph_, target_, edge->node_to()); 

                // calculate the 'real' cost to this node from the source (G)
                float g_cost = costs_of_g_[next_closest_node] + edge->cost();

                // if the node has not been added to the frontier, add it and update the G and F costs
                if (nullptr == search_frontier_[edge->node_to()])
                {
                    costs_of_f_[edge->node_to()] = g_cost + h_cost;
                    costs_of_g_[edge->node_to()] = g_cost;

                    pq.insert(edge->node_to());

                    search_frontier_[edge->node_to()] = edge;
                }
                // if this node is already on the frontier but the cost to get here
                // is cheaper than has been found previously, update the node
                // costs and frontier accordingly.
                else if ((g_cost < costs_of_g_[edge->node_to()]) && 
                         (nullptr == shortest_path_[edge->node_to()]))
                {
                    costs_of_f_[edge->node_to()] = g_cost + h_cost;
                    costs_of_g_[edge->node_to()] = g_cost;

                    pq.changePriority(edge->node_to());

                    search_frontier_[edge->node_to()] = edge;
                }
            }
        }
    }

private:
    // create a typedef for the edge type used by the graph
    //typedef typename Graph::EdgeType Edge;

    const Graph& graph_;

    // indexed into my node. Contains the 'real' accumulative cost to that node
    std::vector<float> costs_of_g_; 

    // indexed into by node. Contains the cost from adding costs_of_g_[n] to
    // the heuristic cost from n to the target node. This is the vector the
    // IndexedPriorityQueueLow indexes into.
    std::vector<float> costs_of_f_;

    std::vector<const Edge*> shortest_path_;
    std::vector<const Edge*> search_frontier_;

    int source_;
    int target_;
};

} // namespace graph

} // namespace gamer

#endif // CITY_HUNTER_SRC_GRAPH_ALGORITHMS_H_