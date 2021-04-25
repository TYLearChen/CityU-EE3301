/**
 *  Topic: [Week 13] [LeetCode] [Graph] 399. Evaluate Division
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 13, LeetCode, Directed Graph, Weighted Graph, Adjacency List, Edge List, Reciprocal
 *  Problem: https://leetcode.com/problems/evaluate-division/
 **/

class Solution 
{
    /** Since the graph might be cyclic, to avoid visiting nodes in cycle, remove the visited nodes from list **/
    unordered_set<string*> exist;
    double dfs(const string& src, const string& cur, const string& dest,
               const vector<vector<string>>& equations, const vector<double>& values)
    {
        double ans = 0;
        /** if src or dest not in the list **/
        if (exist.find(cur) == exist.end() && exist.find(src) == exist.end()) 
            return 0;
        /** if reach the destination **/
        else if (cur == dest) 
            ans = 1;
        /** perform DFS **/
        else
        {
            for (int i = 0; i < equations.size() && !ans; i++)
            {
                vector<string> equ = equations[i];
                if (equ[0] == cur && src != equ[1])
                {
                    exist.erase(cur);
                    ans = values[i] * dfs(equ[0], equ[1], dest, equations, values);
                    exist.insert(cur);
                }
                if (equ[1] == cur && src != equ[0])
                {
                    exist.erase(cur);                    
                    ans = 1/values[i] * dfs(equ[1], equ[0], dest, equations, values);
                    exist.insert(cur);
                }
            }
        }
        return ans;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        /** record all nodes in the edge list **/
        for (vector<string> equ: equations)
        {
            exist.insert(equ[0]);
            exist.insert(equ[1]);
        }
        vector<double> ans_queries(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++)
        {
            double ans = dfs("*", queries[i][0], queries[i][1], equations, values);
            if (ans) ans_queries[i] = ans;
        }
        return ans_queries;
    }
};