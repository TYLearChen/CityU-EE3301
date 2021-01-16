#include <vector>
#include <iostream>
/* 
 * Topic: [Week 1] [LeetCode] [Graph] 1615. Maximal Network Rank
 * Author: CHEN, TSUNG-YU
 * Keyword: Week 1, LeetCode, Graph, Medium, C++, Maximal Network Rank, Degree, Simple Graph, Vector, Adjacent
 */

using namespace std;
struct Node
{
    int name;
    int degree;
};
bool compareEdge(vector<int> edge1, vector<int> edge2)
{
    /** edge1 and edge2 are are in the form of (Node1.name, Node2.name) 
     *  Designed for the built-in sort API
     *  With this compare function, edge whose first node's name (an int) is small will be placed in the front
     *  If two edges have the same first node, edge whose second node's name (an int) is small will be placed in the front
    **/
    if (edge1[0] > edge2[0])
        return false;
    else if (edge1[0] == edge2[0])
        return (edge1[1] < edge2[1]);
    else
        return true;
}
bool compareNode(Node node1, Node node2)
{
    /** Designed for the built-in sort API
     *  Nodes with larger degree will be placed in the front
     *  If the degree of two node are the same, the one with small name (name is an int) will be placed in the front.
     **/

    if (node1.degree > node2.degree)
        return true;
    else if (node1.degree == node2.degree)
        return node1.name < node2.name;
    else
        return false;
}
int numOfTop2(Node node[], int n)
{
    /** Return the number of nodes having top-2 most degrees **/
    int cur_deg = node[0].degree;
    int cur_ctr = 1;
    
    for (int i = 1; i < n; i++)
    {
        if (node[i].degree == cur_deg)
            cur_ctr += 1;
        else if (cur_ctr == 1)
        {
            cur_deg = node[i].degree;
            cur_ctr += 1;
        }
        else
            break;
    }
    return cur_ctr;
}
bool isConnected(Node n1, Node n2, vector<vector<int> >& roads)
{
    /** Determining whether two nodes are adjacent **/
    bool connected = false;
    if (n1.name > n2.name)
    {
        Node tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
    for (vector<int>::size_type i = 0; i != roads.size(); i++)
    {
        connected = (roads[i][0] == n1.name && roads[i][1] == n2.name);
        if (connected)
            break;
    }
    return connected;
}
class Solution
{
    public:
        int maximalNetworkRank(int n, vector<vector<int> >& roads)
        {
            /** Initialising a Node array storing the degree of each node **/
            Node node[n];
            for (int i = 0; i < n; i++)
            {
                node[i].name = i;
                node[i].degree = 0;
            }

            /** Counting degree of each edge **/
            for (vector<int>::size_type i = 0; i != roads.size(); i++)
            {
                sort(roads[i].begin(), roads[i].end());
                for (vector<int>::size_type j = 0; j != roads[i].size(); j++)
                    node[roads[i][j]].degree += 1;
            }
            
            /** Generating a list with top-2 number of degrees **/
            sort(roads.begin(), roads.end(), compareEdge);
            sort(node, node+n, compareNode);
            int num = numOfTop2(node, n);
            int maximal_rank = -1;
            for (int i = 0; i < num; i++)
            {
                for (int j = i+1; j < num; j++)
                {
                    int cur_rank = node[i].degree + node[j].degree - isConnected(node[i], node[j], roads);
                    maximal_rank = maximal_rank > cur_rank ? maximal_rank : cur_rank;
                }
            }
            return maximal_rank;
        }
};

/** Code for validation **/
int main()
{
    int n = 2;
    vector<int> tmp(2, 0);
    vector<vector<int> > roads;

    for (int i = 0; i < 1; i++)
    {
        roads.push_back(tmp);
    }
    
    roads[0][0] = 1;
    roads[0][1] = 0;
    
    Solution s;
    cout << s.maximalNetworkRank(n, roads);
}
