/**
 *  Topic: [Week 7] [LeetCode] [Tree] 1641. Count Sorted Vowel Strings
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 7, LeetCode, Dynamic Programming
 **/

class Solution {
public:
    int countVowelStrings(int n) 
    {        
        /** initialising the loopUp table with 0 
            Since a row will not be used after its next row is computed, only one row is needed.
            (e.g., to compute the case when n=4, we will use only info of n=3)
            We can thus reduce the use of memory
        **/
        int num_comb[5] = {0};
        int sum = 0;
        
        /** 0 1 2 3 4 **/
        /** a e i o u **/
        for (int j = 0; j < n; j++)
            for (int i = 4; i >= 0; i--)
            {
                /** boundary conditioin **/
                if (j == 0)
                    num_comb[i] = 1;
                /** recurrence equation **/
                else
                    num_comb[i] = (i == 4) ?  num_comb[i] : num_comb[i+1] + num_comb[i];
                
                /** collect anwser for the last iteration **/
                if (j == n-1)
                    sum += num_comb[i]; 
            }
        return sum;
    }
};