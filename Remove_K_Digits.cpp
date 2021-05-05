/**
 *  Topic: [Week 15] [LeetCode] [Greedy] 402. Remove K Digits
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 15, LeetCode, Greedy, Stack
 *  Problem: https://leetcode.com/problems/remove-k-digits/
 **/
class Solution 
{
public:
    string removeKdigits(string num, int k) 
    {
        int toDel = k;
        stack<char> remain;
        // dummy item to prevent underflow
        remain.push('0'-1);
        int idx = 0;
        while (k > 0)
        {
            // greedy approach to make the small digit as 'significant' as possible
            if (num[idx] >= remain.top())
                remain.push(num[idx++]);
            else
            {
                remain.pop();
                k--;
            }
        }
        while (idx < num.length())
            remain.push(num[idx++]);

        // put the item in the stack back to string
        for (int i = remain.size(); i > 1; i--)
        {
            num[i-2] = remain.top();
            remain.pop();
        }
        
        // remove leading 0
        string new_str = num.substr(0, num.length()-toDel);
        for (int i = 0; i < new_str.length(); i++)
        {
            if (new_str[i] != '0')
                return new_str.substr(i, new_str.length()-i);
        }
        
        return "0";
    }
};