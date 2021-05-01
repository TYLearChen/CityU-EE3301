/**
 *  Topic: [Week 14] [LeetCode] [Graph] 86. Partition List
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 14, LeetCode, Graph, Tree
 *  Problem: https://leetcode.com/problems/reverse-linked-list-ii/
 **/
class Solution 
{
    ListNode* find(ListNode* start, int distance)
    {
        ListNode* cur = start;
        for (int i = 1; i < distance; i++)
            cur = cur->next;
        return cur;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode *before_cur, *cur, *after_cur;
        
        if (left == 1)
        {
            before_cur = nullptr;
            cur = head;
        }
        else
        {
            before_cur = find(head, left-1);
            cur = before_cur->next;
        }
        after_cur = cur->next; // might be nullptr
        
        ListNode *before_start, *start;

        for (int cur_idx = left; cur_idx <= right; cur_idx++)
        {
            if (cur_idx == left)
            {
                before_start = before_cur;
                start = cur;
            }
            else
                cur->next = before_cur;
            
            if (cur_idx == right)
            {
                start->next = after_cur;
                if (before_start == nullptr)
                    /** first node to reverse is head **/
                    head = cur;
                else
                    before_start->next = cur;
            }
            before_cur = cur;
            cur = after_cur;
            if (after_cur != nullptr)
                after_cur = after_cur->next;
        }
        return head;      
    }
};