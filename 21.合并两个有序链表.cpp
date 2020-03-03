/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (58.56%)
 * Likes:    752
 * Dislikes: 0
 * Total Accepted:    150.9K
 * Total Submissions: 257.4K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
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
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // dummyHead
        ListNode node = ListNode(0), *root = &node, *i = root;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                i->next = l1;
                l1 = l1->next;
            } else {
                i->next = l2;
                l2 = l2->next;
            }
            i = i->next;
        }
        i->next = l1 ? l1 : l2;
        return root->next;
    }
};
// @lc code=end
