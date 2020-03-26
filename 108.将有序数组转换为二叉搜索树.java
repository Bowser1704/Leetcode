import java.util.*;
/*
 * @lc app=leetcode.cn id=108 lang=java
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (69.87%)
 * Likes:    360
 * Dislikes: 0
 * Total Accepted:    56.8K
 * Total Submissions: 81.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0) return null;
        return dfs(nums, 0, nums.length-1);
    }

    // [low. high) 必须 [l, h]???
    TreeNode dfs(int[] nums, int low, int high) {
        if (low > high) return null;
        int mid = low + (high - low) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = dfs(nums, low, mid - 1);
        root.right = dfs(nums, mid+1, high);
        return root;
    }
}
// @lc code=end
class FirstSolution {
    public TreeNode sortedArrayToBST(int[] nums) {
        TreeNode root = dfs(nums);
        return root;
    }

    TreeNode dfs(int[] nums) {
        int len = nums.length;
        if (len == 0) return null;
        TreeNode root = new TreeNode(nums[len / 2]);
        if (len == 1) return root;
        root.left = dfs(Arrays.copyOfRange(nums, 0, len / 2));
        root.right = dfs(Arrays.copyOfRange(nums, len / 2 + 1, len));
        return root;
    }
}