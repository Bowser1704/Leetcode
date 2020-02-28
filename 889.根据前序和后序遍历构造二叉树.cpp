#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (60.67%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 4.1K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * 返回与给定的前序和后序遍历匹配的任何二叉树。
 * 
 * pre 和 post 遍历中的值是不同的正整数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * 输出：[1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
 * 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return create(0, pre.size() - 1, 0, post.size() - 1, pre, post);
    }
    TreeNode* create(int preL, int preR, int postL, int postR, vector<int>& pre, vector<int>& post) {
        if (preL > preR || postL > postR) return nullptr;

        TreeNode* root = new TreeNode(pre[preL]);
        if (preL == preR) return root;

        int k = postL;
        for (int i = postL; i < postR; i++) {
            if (post[i] == pre[preL+1]) {
                k = i;
                break;
            }
        }
        int numLeft = k-postL+1;
        root->left = create(preL + 1, preL + numLeft, postL, postL + numLeft - 1, pre, post);
        root->right = create(preL + 1 + numLeft, preR, postL + numLeft, postR - 1, pre, post);

        return root;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> post = {4,5,2,6,7,3,1};
    TreeNode* root =  solution.constructFromPrePost(pre, post);
    return 0;
}