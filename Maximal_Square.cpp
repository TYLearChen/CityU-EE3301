/**
 *  Topic: [Week 15] [LeetCode] [DP] 221. Maximal Square
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 15, LeetCode, Dynamic Programming, Matrix
 *  Problem: https://leetcode.com/problems/maximal-square/
 **/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        /** length of square with all ones **/
        int max_side = 0;
        /** numbers of row and col of the whole graph **/
        int num_row = matrix.size();
        int num_col = matrix[0].size();
        /** dp array to store computed results **/
        vector<vector<int> > dp(num_row, vector<int>(num_col, 0));
        
        /** compute the results cell by cell form bottom right to top left 
            based on the results computed previously **/
        for (int row = num_row-1; row >= 0; row--)
            for (int col = num_col-1; col >= 0; col--)
            {
                /** boundary condition 1 **/
                if ((row == num_row-1) || (col == num_col-1))
                    dp[row][col] = (matrix[row][col] == '1');
                /** boundary condition 2 **/
                else if (dp[row+1][col+1] == 0)
                    dp[row][col] = (matrix[row][col] == '1');
                /** recrrent relation **/
                else 
                {
                    int side = dp[row+1][col+1] + 1;
                    bool all_one = true;
                    
                    int step;
                    /** check new cell **/
                    for (step=0; step<side && all_one; step++)
                        all_one = (matrix[row+step][col] == '1') && (matrix[row][col+step] == '1');
                    
                    dp[row][col] = step - !all_one;
                }
                /** update maximum **/
                max_side = max(dp[row][col], max_side);
            }
        return max_side*max_side;
    }
};