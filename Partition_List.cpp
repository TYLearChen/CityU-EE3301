/**
 *  Topic: [Week 14] [LeetCode] [Graph] 86. Partition List
 *  Author: CHEN, TSUNG-YU
 *  Keyword: Week 14, LeetCode, Graph
 *  Problem: https://leetcode.com/problems/partition-list/
 **/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smaller_head = nullptr, *smaller_tail = nullptr;
        ListNode *rest_head    = nullptr, *rest_tail    = nullptr;

        ListNode *cur = head;
        while (cur != nullptr)
        {
            if (cur->val < x)
            {
                /** first smaller node **/
                if (smaller_head == nullptr)
                {
                    smaller_head = cur;
                }
                /** rest smaller nodes **/
                else
                {
                    smaller_tail->next = cur;
                }
                smaller_tail = cur;
            }
            else
            {
                /** first equ node **/
                if (rest_head == nullptr)
                {
                    rest_head = cur;
                }
                /** rest equ nodes **/
                else
                {
                    rest_tail->next = cur;
                }
                rest_tail = cur;
            }
            cur = cur->next;
        }
        
        if (smaller_head != nullptr)
        {
            head = smaller_head;
            smaller_tail->next = rest_head;
        }
        else
            head = rest_head;
        if (rest_tail != nullptr)
            rest_tail->next = nullptr;
        return head;
    }
};