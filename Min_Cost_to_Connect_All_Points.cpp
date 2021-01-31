#include <math.h>
class Solution {
    struct edge 
    {
        int node1;
        int node2;
        int weight;
        edge () {}
        edge (int node1, int node2, int weight) 
        {
            this->node1 = node1;
            this->node2 = node2;
            this->weight = weight;
        }
        bool operator < (const edge& that) const
        {
            if (this->weight != that.weight) return (this->weight > that.weight);
            else if (this->node1 != that.node1) return (this->node1 < that.node1);
            else return (this->node2 < that.node2);
        }
    };
    int calDistance(vector<int>& p1, vector<int>& p2)
    {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        bool V[points.size()];
        priority_queue<edge> E;
        vector<edge> MST;
        for (int i = 0; i < points.size(); i++)
        {
            V[i] = false;
            // for (int j = i+1; j < points.size(); j++)
            // {
            //     E.push_back(edge(i, j, calDistance(points[i], points[j])));
            // }
        }
        
        int new_node = 0;
        V[new_node] = true;
        int cost = 0;
        int count = 0;
        while (count < points.size() - 1)
        {
            /** Adding distance between new_node and unvisited node to E **/
            for (int i = 0; i < points.size(); i++)
                if (!V[i])
                    E.push(edge(new_node, i, calDistance(points[new_node], points[i])));
   
            bool found = false;
            while (!found)
            {
                /** inside of the edge has been visited, while the other hasn't **/    
                if ((V[E.top().node1] && !V[E.top().node2]) || (!V[E.top().node1] && V[E.top().node2]))
                {
                    cost += E.top().weight;
                    new_node = V[E.top().node2] ? E.top().node1 : E.top().node2;
                    V[new_node] = true;
                    found = true;
                    count++;
                } 
                E.pop();
            }
        }
        
        return cost;
    }
};