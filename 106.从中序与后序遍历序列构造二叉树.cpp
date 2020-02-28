#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (65.40%)
 * Likes:    134
 * Dislikes: 0
 * Total Accepted:    18.9K
 * Total Submissions: 28.8K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = create(0, inorder.size() - 1, 0, postorder.size() - 1, postorder, inorder);
        return root;
    }
    TreeNode* create(int inL, int inR, int postL, int postR, vector<int>& postorder, vector<int>& inorder) {
        if (postL > postR) return nullptr;

        int rootVal = postorder[postR];
        TreeNode* root = new TreeNode(rootVal);

        int k = 0;
        for (int i = inL; i <= inR; i++) {
            if (rootVal == inorder[i]) {
                k = i;
                break;
            }
        }
        int numLeft = k - inL;  //

        root->left = create(inL, k - 1, postL, postL + numLeft-1, postorder, inorder);
        root->right = create(k + 1, inR, postL + numLeft , postR-1, postorder, inorder);

        return root;
    }
};
// @lc code=end
