/**
 *  Topic: [Week 11] [LeetCode] [DP] 122. Best Time to Buy and Sell Stock II
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 11, LeetCode, Dynamic Programming
 *  Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 **/

class Solution 
{
    static const int max_day = 3e4;
    int dp[max_day][2], visited[max_day][2] = { 0 };
    
    int buyOrNot(vector<int>& prices, int day, bool haveStock)
    {
        int profit;
        /** boundary condition **/
        if (day == prices.size()) profit = 0;
        /** Return save result (dynamic programming) **/
        else if (visited[day][haveStock]) profit = dp[day][haveStock];
        /** Recurrence relation **/
        else
        {
            if (haveStock)
            {
                int doNothing = buyOrNot(prices, day + 1, true);
                int sellStock = buyOrNot(prices, day + 1, false) + prices[day];
                profit = max(doNothing, sellStock);
            }
            else
            {
                int doNothing = buyOrNot(prices, day + 1, false);
                int buyStock  = buyOrNot(prices, day + 1, true) - prices[day]; 
                profit = max(doNothing, buyStock);
            }
            /** save calculated result **/
            dp[day][haveStock] = profit;
            /** marked visited situation **/
            visited[day][haveStock] = 1;
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) 
    {   
        /** call recurent function **/   
        return buyOrNot(prices, 0, false);
    }
};