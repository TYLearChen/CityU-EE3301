/**
 *  Topic: [Week 3-A] [LeetCode] [Graph] 743. Network Delay Time
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 3, LeetCode, Graph, Medium, C++, Dijkstra's algorithm, Directed Weighted Graph
 **/

struct node
{
    int name;
    int cost;
    int pred;
    node() {}
    node (int name, int cost, int pred)
    {
        this->name = name;
        this->cost = cost;
        this->pred = pred;        
    }
};
struct greaterCost
{
    bool operator() (const node* n1, const node* n2)
    {
        return n1->cost > n2->cost;
    }
};

class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        /** n nodes, start from k **/
        map<int, node> V;
        map<int, node> Q;
        
        /** Initialising Q by pushing all nodes in Q **/
        for (int i = 1; i <= n; i++)
            Q[i] = node(i, INT_MAX*(i != k), -1);            
        
        while (!Q.empty())
        {
            /** getting node with min cost **/
            int min_idx = Q.rbegin()->first;
            for (int i = 1; i <= n; i++)
                if (Q.find(i) != Q.end() && 
                    Q[i].cost < Q[min_idx].cost)
                    min_idx = i;
            
            if (Q[min_idx].cost == INT_MAX)
                return -1;
            
            /** updating cost for all nodes adjacent to N **/
            for (vector<int> edge : times)
            {
                if (edge[0] == min_idx)
                {
                    int dest = edge[1];
                    if (Q.find(dest) != Q.end() && 
                        Q[dest].cost > Q[min_idx].cost + edge[2])
                    {
                        Q[dest].cost = Q[min_idx].cost + edge[2];
                        Q[dest].pred = min_idx;
                    }
                }
            }
            /** placing min_idx into the club **/
            V[min_idx] = Q[min_idx];
            Q.erase(min_idx);
        }
        
        /** finding the node with the largest cost **/
        int max_idx = 1;
        for (int i = 1; i <= n; i++)
            if (V[i].cost > V[max_idx].cost)
                max_idx = i;
        return V[max_idx].cost;
    }
};
