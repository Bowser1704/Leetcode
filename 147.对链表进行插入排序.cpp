/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 *
 * https://leetcode-cn.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (63.02%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    21.5K
 * Total Submissions: 34.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 对链表进行插入排序。
 * 
 * 
 * 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
 * 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
 * 
 * 
 * 
 * 插入排序算法：
 * 
 * 
 * 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 * 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 * 重复直到所有输入数据插入完为止。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2：
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
//逆向思维。从大到小排序、
class Solution {
   public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* root = new ListNode(-2);
        root->next = head;

        ListNode *tail = head, *cur = head->next;

        while (cur) {
            if (cur->val < tail->val) {
                //node是开始移动的指针
                ListNode* node = root;
                while (node->next && cur->val > node->next->val)
                    node = node->next;
                // node是那个要插入的位置,cur插在node的后面。
                // 开始交换
                tail->next = cur->next;
                cur->next = node->next;
                node->next = cur;

                cur = tail->next;
            } else {
                //减少比较
                tail = tail->next;
                cur = tail->next;
            }
        }
        return root->next;
    }
};
// @lc code=end

int main() {
    Solution solution;
    ListNode* root = new ListNode(4);
    root->next = new ListNode(2);
    root->next->next = new ListNode(1);
    root->next->next->next = new ListNode(3);
    ListNode* node = solution.insertionSortList(root);
}