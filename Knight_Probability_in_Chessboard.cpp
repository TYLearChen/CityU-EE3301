/**
 *  Topic: [Week 15] [LeetCode] [DP] 688. Knight Probability in Chessboard
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 15, LeetCode, Dynamic Programming, Chessboard, Probability
 *  Problem: https://leetcode.com/problems/knight-probability-in-chessboard/
 **/
class Solution {
    // directions for moving the chess
    int move[2][8] = { {1, -1, 1, -1, 2, -2,  2, -2}, 
                       {2, 2, -2, -2, 1,  1, -1, -1} };
    
    // dp array to memorise the visited cell
    float dp[101][25][25] = { 0 };
    
    // determine whether the chess is still on the board
    float outside(int n, int row, int column) 
    { 
        return row < 0 || column < 0 || row >= n || column >= n; 
    }
    
    double getProb(int n, int k, int row, int column)
    {
        float prob;
        
        // base case
        if (!outside(n, row, column)) 
            prob = dp[k][row][column];
        else 
            prob = 1;
        
        // recurrent relation
        if (prob == 0 && k != 0)
        {
            for (int i = 0; i < 8; i++)
                prob += getProb(n, k-1, row+move[0][i], column+move[1][i]) / 8;
            // memorise the result
            dp[k][row][column] = prob;
        }
        
        return prob;
    }
    
public:
    double knightProbability(int n, int k, int row, int column) 
    {
        // driver function
        return 1 - getProb(n, k, row, column);
    }
};