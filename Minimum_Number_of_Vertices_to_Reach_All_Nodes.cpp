/**
 *  Topic: [Week 15] [LeetCode] [Graph] 1557. Minimum Number of Vertices to Reach All Nodes
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 15, LeetCode, Graph, Edge List, In-degree
 *  Problem: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
 **/
class Solution 
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        // an array to store the in-degree of a node
        int arrived[100000] = { 0 };
        // all node with in-degree 0
        vector<int> root;
        for (vector<int> edge : edges)
        {
            // increase in-degree of node 'to' by one
            int to = edge[1];
            arrived[to] += 1;
        }
        // add all node with in-degree to the list of root
        for (int i = 0; i < n; i++)
            if (arrived[i] == 0)
                root.push_back(i);
        return root;
    }
};