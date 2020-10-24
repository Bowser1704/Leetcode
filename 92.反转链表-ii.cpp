/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *start = nullptr;
        ListNode *first = nullptr, *last = head;
        // only need first and end;
        // first->next == start
        // end->next == last
        if (m == 1) {
            while (n-- > 0) last = last->next;
            start = head;
            ListNode *prev = reverseList(start, last);
            start->next = last;
            return prev;
        } else {
            first = head;
            while (n-- > 0) {
                if(--m > 1) 
                    first = first->next;
                last = last->next;
            }
            start = first->next;

            ListNode *prev = reverseList(start, last);

            first->next = prev;
            start->next = last;

            return head;
        }
        return nullptr;
    }

    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode *cur = head, *prev = nullptr, *next = nullptr;
        while (cur != tail) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
// @lc code=end

