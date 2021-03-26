/**
 *  Topic: [Week 10] [LeetCode] [DP] 474. Ones and Zeroes
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 10, LeetCode, Dynamic Programming, Knapsack Problem, 3D Vector
 *  Problem: https://leetcode.com/problems/ones-and-zeroes/
 **/

class Solution 
{
    pair<int, int> count[600];
    bool calculated[600] = { 0 };
    
    void countZeroAndOne(vector<string>& strs, int idx) 
    {
        int num_zero = 0, num_one = 0;
        for (int i = 0; i < strs[idx].length(); i++)
        {
            num_zero += (strs[idx][i] == '0');
            num_one  += (strs[idx][i] == '1');
        }
        count[idx] = make_pair(num_zero, num_one);
        calculated[idx] = true;
    }
    
    int decide(vector<string>& strs, 
               int idx, 
               int num_zero, int num_one, 
               vector<vector<vector<int> > >& dp)
    {
        if (idx == strs.size()) 
            return 0;
        else if (dp[idx][num_zero][num_one] != -1) 
            return dp[idx][num_zero][num_one];
        
        if (!calculated[idx]) 
            countZeroAndOne(strs, idx);
        
        if (num_zero < count[idx].first || num_one < count[idx].second)
            dp[idx][num_zero][num_one] = decide(strs, idx+1, num_zero, num_one, dp);
        else
            dp[idx][num_zero][num_one] = max(decide(strs, idx+1, num_zero-count[idx].first, num_one-count[idx].second, dp) + 1, 
                                             decide(strs, idx+1, num_zero, num_one, dp));
        return dp[idx][num_zero][num_one];
    }

    
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<vector<int> > > dp(strs.size(), 
                                         vector<vector<int> >(m+1, 
                                                              vector<int>(n+1, -1)));
        return decide(strs, 0, m, n, dp);
    }
};