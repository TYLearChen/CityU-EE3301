/**
 *  Topic: [Week 2] [LeetCode] [Graph] 785. Is Graph Bipartite?
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 2, LeetCode, Graph, Medium, C++, Bipartite, Adjacent, Adjacency List, Node List, Breadth-first Search
 **/

class Solution 
{
    public:
        bool isBipartite(vector<vector<int>>& graph) 
        {
            map<int, vector<int> > node_list;
            int node_set[graph.size()];
            queue< pair<int, vector<int> > > to_visit;
            
            for (int i = 0; i < graph.size(); i++)
            /** creating a node list (adjacency list) for the graph and initialising the array storing where the nodes belong (V_0 or V_1) **/
            {
                node_list[i] = graph[i];
                 node_set[i] = -1;           
            }
            
            int current_set = 1;
            while (to_visit.size() != 0 || node_list.size() != 0)
            /** performing BFS on each component of the graph **/
            {
                for (int node = 0; node < graph.size() && to_visit.size() == 0; node++)
                /** initiating BFS on a new component **/
                {
                    if (node_list.find(node) != node_list.end())
                    {
                        to_visit.push(pair<int, vector<int> > (node, node_list[node]));
                        node_list.erase(node);
                        node_set[node] = current_set;
                    }
                }

                pair<int, vector<int> > adjecent_nodes = to_visit.front(); to_visit.pop();
                int previous_set = node_set[adjecent_nodes.first];
                current_set  = (previous_set +1) %2;

                for (int node : adjecent_nodes.second)
                {
                    if (node_set[node] == previous_set)
                    /** a pair of adjecent nodes belong to the same set **/
                        return false;
                    else
                    /** found a node belongs to no set **/
                        node_set[node] = current_set;
                    
                    if (node_list.find(node) != node_list.end())
                    {
                    /** enqueuing the node for BFS on the next level of depth **/
                        to_visit.push(pair<int, vector<int> > (node, node_list[node]));
                        node_list.erase(node);
                    }
                }
            }
            return true;
        }
};