/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 *
 * https://leetcode-cn.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (37.75%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    8.4K
 * Total Submissions: 22.2K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
 * 
 * 注意：两个节点之间的路径长度由它们之间的边数表示。
 * 
 * 示例 1:
 * 
 * 输入:
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。
 * 
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
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
    bool check = true;
    int longestUnivaluePath(TreeNode *root) {
        return recursion(root);
    }
    int recursion(TreeNode *root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        if (root->left != nullptr && root->right != nullptr) {
            if (root->val != root->left->val && root->val != root->right->val) {
                int l = recursion(root->left);
                int r = recursion(root->right);
                if (l < r) return r;
                return l;
            } else if (root->val == root->right->val && root->val == root->left->val) {
                int l = recursion(root->left);
                int r = recursion(root->right);
                int x = l;
                if (r > x) x = r;
                if (check == true) {
                    check = false;
                    return x+2;
                }
                return x+1;
            }
        }
        if (root->left != nullptr && root->val == root->left->val) {
            return 1 + recursion(root->left);
        } else if (root->right != nullptr && root->val == root->right->val) {
            return 1 + recursion(root->right);
        }
        return 0;
    }
};
// @lc code=end

//没有考虑到，是任意两点，这不是树，把它看做图会更好。这个题目，一点都不简单。。。。
class ErrorSolution {
   public:
    int longestUnivaluePath(TreeNode *root) {
        return recursion(root);
    }
    int recursion(TreeNode *root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        if (root->left != nullptr && root->right != nullptr) {
            if (root->val != root->left->val && root->val != root->right->val) {
                int l = recursion(root->left);
                int r = recursion(root->right);
                if (l < r) return r;
                return l;
            } else if (root->val == root->right->val && root->val == root->left->val) {
                int l = recursion(root->left);
                int r = recursion(root->right);
                if (l < r) return r+2;
                return l+2;
            }
        }
        if (root->left != nullptr && root->val == root->left->val) {
            return 1 + recursion(root->left);
        } else if (root->right != nullptr && root->val == root->right->val) {
            return 1 + recursion(root->right);
        }
        return 0;
    }
};