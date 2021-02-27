class Solution {
public:
    
    int pickMax(vector<int>& piles, int start, int end, int** score)
    {
        if (score[start][end] != 0)
            return score[start][end];
        else if ((end - start) + 1 == 2)
            score[start][end] = abs(piles[start] - piles[end]);
        else if ((end - start) % 2 == 0)
            score[start][end] = max(piles[start] + pickMax(piles, start+1, end, score), 
                                    piles[end]   + pickMax(piles, start, end-1, score));
        else
            score[start][end] = -max(piles[start] + pickMax(piles, start+1, end, score), 
                                     piles[end]   + pickMax(piles, start, end-1, score));
        return score[start][end];
    }
    
    bool stoneGame(vector<int>& piles) 
    {
        int** score = new int*[piles.size()];
        for (int i=0; i<piles.size(); i++)
        {
            score[i] = new int[piles.size()];
            memset(score[i], 0, sizeof(int)*piles.size());
        }
        
        return pickMax(piles, 0, piles.size()-1, score);
    }
};
