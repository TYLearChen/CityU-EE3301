/**
 *  Topic: [Week 6] [LeetCode] [DP] 877. Stone Game
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 6, LeetCode, Dynamic Programming, Medium, C++, Minimax Search, Recursion
 **/

class Solution {
public:
    
    int pickMax(vector<int>& piles, int start, int end, int** score)
    {
        /** DP table for values computed before **/
        if (score[start][end] != 0)
            return score[start][end];

        /** boundary condition **/
        else if (end == start)
            score[start][end] = piles[start];
        /** Max policy (our turn) **/
        else if ((end - start) % 2 == 0)
            score[start][end] = max(piles[start] + pickMax(piles, start+1, end, score), 
                                    piles[end]   + pickMax(piles, start, end-1, score));
        /** Min policy (others' turn) **/       
        else
            score[start][end] = -max(piles[start] + pickMax(piles, start+1, end, score), 
                                     piles[end]   + pickMax(piles, start, end-1, score));

        return score[start][end];
    }
    
    bool stoneGame(vector<int>& piles) 
    {
        /** Creating and initialising a DP table **/
        int** score = new int*[piles.size()];
        for (int i=0; i<piles.size(); i++)
        {
            score[i] = new int[piles.size()];
            memset(score[i], 0, sizeof(int)*piles.size());
        }
        
        return pickMax(piles, 0, piles.size()-1, score);
    }
};