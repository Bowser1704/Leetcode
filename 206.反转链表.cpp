/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (67.30%)
 * Likes:    803
 * Dislikes: 0
 * Total Accepted:    176.3K
 * Total Submissions: 260.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 尾递归 和 迭代 复杂度差不多、
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) return pre;
        ListNode* next = cur->next;
        cur->next = pre;
        return reverse(cur, next);
    }
};
// @lc code=end

class IterativeSolution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* root = new ListNode(head->val);
        head = head->next;
        while (head) {
            ListNode* temp = head->next;

            head->next = root;
            root = head;

            head = temp;
        }
        return root;
    }
};