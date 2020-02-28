/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 *
 * https://leetcode-cn.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (36.80%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 17.7K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 * 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 * 
 * 一般来说，删除节点可分为两个步骤：
 * 
 * 
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 * 
 * 
 * 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
 * 
 * 示例:
 * 
 * 
 * root = [5,3,6,2,4,null,7]
 * key = 3
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * 给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
 * 
 * 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 4   6
 * ⁠/     \
 * 2       7
 * 
 * 另一个正确答案是 [5,2,6,null,4,null,7]。
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 2   6
 * ⁠  \   \
 * ⁠   4   7
 * 
 * 
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *pp = nullptr, *p = root;
        while (p) {
            if (key > p->val) {
                pp = p;
                p = p->right;
            } else if (key < p->val) {
                pp = p;
                p = p->left;
            } else {
                break;
            }
        }
        if (p == nullptr) return root;
        //分三种情况，但是第一种情况可以用到，无子节点和一个子节点的情况.
        if (p->left != nullptr && p->right != nullptr) {
            TreeNode *minRight = p->right, *minRightP = p;
            while (minRight->left != nullptr) {
                minRightP = minRight;
                minRight = minRight->left;
            }
            p->val = minRight->val;
            //删除minRight.利用下面的代码。后两种情况。
            p = minRight;
            pp = minRightP;
        }
        //后两种情况
        TreeNode* child = nullptr;
        if (p->left != nullptr)
            child = p->left;
        else if (p->right != nullptr)
            child = p->right;

        if (pp == nullptr) {
            root = child;
            return root;
        } else if (pp->left == p)
            pp->left = child;
        else
            pp->right = child;

        return root;
    }
};
// @lc code=end
