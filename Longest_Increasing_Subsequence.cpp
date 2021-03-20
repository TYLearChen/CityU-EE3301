/**
 *  Topic: [Week 8] [LeetCode] [DP] 300. Longest Increasing Subsequence
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 9, LeetCode, Dynamic Programming
 *  Reference: https://leetcode.com/problems/longest-increasing-subsequence/discuss/74836/My-easy-to-understand-O(n2)-solution-using-DP-with-video-explanation
 *  Problem: https://leetcode.com/problems/longest-increasing-subsequence/
 **/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int result = 0;
        /** an array for DP **/
        int* dp = new int[nums.size()];
        
        /** maintaining two pointers. **/
        for (int i = 0; i < nums.size(); i++)
        /** one points to the new element. **/
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            /**  another points to viewed elements. **/
                if (nums[i] > nums[j])
                /** if the new element is larger than the view element **/
                    dp[i] = max(dp[i], dp[j]+1);
            
            /**keeping tracking the maximum **/
            result = max(result, dp[i]);
        }
        return result;
    }
};