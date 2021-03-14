/**
 *  Topic: [Week 8] [LeetCode] [DP] 309. Best Time to Buy and Sell Stock with Cooldown
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 8, LeetCode, Dynamic Programming
 **/

#define SELL 0
#define BUY  1
#define WITH 2
#define WO   3

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int> > property(2, vector<int>(4, 0));
        for (int day = 0; day < prices.size(); day++)
        {
            /** boundary condition **/
            if (day == 0)
            {
                property[day%2][SELL] = 0;
                property[day%2][BUY]  = -prices[day];
                property[day%2][WITH] = 0;
                property[day%2][WO]   = 0;
            }
            else if (day == 1)
            {
                property[day%2][SELL] = property[(day-1)%2][BUY] + prices[day];
                property[day%2][BUY]  = property[(day-1)%2][WO]  - prices[day];
                property[day%2][WITH] = property[(day-1)%2][BUY];
                property[day%2][WO]   = property[(day-1)%2][WO];
            }
            else
            {
                property[day%2][SELL] = max(
                    property[(day-1)%2][BUY]  + prices[day],
                    property[(day-1)%2][WITH] + prices[day]
                );
                property[day%2][BUY]  = property[(day-1)%2][WO]  - prices[day];
                property[day%2][WITH] = max(
                    property[(day-1)%2][BUY],
                    property[(day-1)%2][WITH]
                );
                property[day%2][WO]   = max(
                    property[(day-1)%2][WO],
                    property[(day-1)%2][SELL]
                );
            }
        }
        return max(
            max(property[(prices.size()-1)%2][BUY], property[(prices.size()-1)%2][SELL]),
            max(property[(prices.size()-1)%2][WITH], property[(prices.size()-1)%2][WO])
        );
    }
};