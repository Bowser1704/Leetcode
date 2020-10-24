/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        // Reverse Linked list.
        // fast and slow pointer.
        ListNode *newHead = reverseLinkedList(spliteLinkedList(head));
        while (newHead) {
            if (head->val != newHead->val) return false;
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
    ListNode* spliteLinkedList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode *cur = head, *prev = nullptr, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
// @lc code=end

/*
1->2->2->1
*/