/**
 *  Topic: [Week 15] [LeetCode] [DP] 357. Count Numbers with Unique Digits
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 15, LeetCode, Java, Dynamic Programming, Numeric
 *  Problem: https://leetcode.com/problems/count-numbers-with-unique-digits/
 **/

import java.util.ArrayList;
class Solution {
/*
 * n = 0 => 1
 * n = 1 => 9 + 1
 * n = 2 => 9*9 + 9 + 1
 * n = 3 => 9*9*8 + 9*9 + 9 + 1
 * n = 4 => 9*9*8*7 + 9*9*8 + 9*9 + 9 + 1
 */
    public int countNumbersWithUniqueDigits(int n) {
        // number of new numbers resulting from adding one new digit to 'c' digits
        int c = 0;
        final int max = 10;

        int sum = 0;
        for (int i = 0; i <= n && i < max; i++)
        {   
            // boundary condition 1
            if (i == 0)
                c = 1;
            // boundary condition 2
            else if (i == 1)
                c = 9;
            // recurrence relation
            else
                c *= (max+1-i);
            
            sum += c;
        }
        return sum;
    }
}