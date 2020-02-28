#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (48.02%)
 * Likes:    413
 * Dislikes: 0
 * Total Accepted:    60.5K
 * Total Submissions: 125.9K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        return mergeklist(lists, 0, lists.size() - 1);
    }
    ListNode* mergeklist(vector<ListNode*>& lists, int b, int e) {
        if (b > e) return nullptr;
        if (b == e) return lists[b];
        int m = b + ((e - b) >> 1);
        //递归 分治
        return merge(mergeklist(lists, b, m), mergeklist(lists, m + 1, e));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode(0), *i = root;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                i->next = l2;
                l2 = l2->next;
            } else {
                i->next = l1;
                l1 = l1->next;
            }
            i = i->next;
        }
        i->next = l1 ? l1 : l2;
        return root->next;
    }
};
// @lc code=end

/*
1. 把所有元素拿下来，排序。
2. 取k个指针，每次比较k下，谁小，谁向下移。
3. 不停的merge， 从0,1,2,3。。。。
3. 递归，分治法，中间merge。
*/

class ThirdSolution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode* result = merge(lists[0], lists[1]);
        for (int i = 2; i < lists.size(); i++) {
            result = merge(result, lists[i]);
        }
        return result;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode(0), *i = root;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                i->next = l2;
                l2 = l2->next;
            } else {
                i->next = l1;
                l1 = l1->next;
            }
            i = i->next;
        }
        i->next = l1 ? l1 : l2;
        return root->next;
    }
};