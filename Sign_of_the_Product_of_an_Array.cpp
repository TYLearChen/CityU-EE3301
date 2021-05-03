/**
 *  Topic: [Week 15] [LeetCode] [DP] 1822. Sign of the Product of an Array
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 15, LeetCode, Dynamic Programming, Overflow
 *  Problem: https://leetcode.com/problems/sign-of-the-product-of-an-array/
 **/

class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        // int sign = 1;
        bool sign = true; // DP storage
        for (int n: nums)
        {
            // Cannot do this, sign will overflow quickly
            // sign *= n
            
            /** if any of the num in the array is zero, product will be zero **/
            if (n == 0) 
                return 0;
            /** toggle the sign when encounter negative number **/
            else if (n < 0) 
                sign = !sign;
        }
        return sign ? 1 : -1;
    }
};