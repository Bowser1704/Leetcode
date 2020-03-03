/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (63.96%)
 * Likes:    428
 * Dislikes: 0
 * Total Accepted:    43.5K
 * Total Submissions: 67.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        // root = dummyHead
        ListNode node = ListNode(-1);
        auto root = &node;
        root->next = head;
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }

        for (int sz = 1; sz < len; sz *= 2) {
            // tail表示已经merge链表的尾部
            auto cur = root->next, tail = root;

            while (cur) {
                auto left = cur;
                auto right = cut(left, sz);
                cur = cut(right, sz);

                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return root->next;
    }

    // splite操作，切掉前n个节点，返回后半部分。
    ListNode* cut(ListNode* head, int n) {
        auto p = head;
        while (--n && p)
            p = p->next;
        
        //防止head 没有n个节点
        if(!p) return nullptr;

        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    // leetcode 21
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // root == dummyHead
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

int main() {
    Solution solution;
    ListNode* root = new ListNode(-1);
    root->next = new ListNode(5);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(0);
    ListNode* node = solution.sortList(root);
}