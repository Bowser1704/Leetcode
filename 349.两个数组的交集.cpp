#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (68.28%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    53.6K
 * Total Submissions: 78.4K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;
        unordered_set<int> set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (set.erase(num))
                nums2[count++] = num;
        }
        return vector<int>(nums2.begin(), nums2.begin() + count);
    }
};
// @lc code=end
