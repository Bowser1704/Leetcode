#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (38.21%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    47.9K
 * Total Submissions: 125.3K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        int lo = 0, hi = length - 1, first = -1, last = -1;
        vector<int> result;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                if (mid == 0 || nums[mid - 1] != target) {
                    first = mid;
                    break;
                } else {
                    hi = mid - 1;
                }
            }
        }
        lo = 0, hi = length - 1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                if (mid == length - 1 || nums[mid + 1] != target) {
                    last = mid;
                    break;
                } else {
                    lo = mid + 1;
                }
            }
        }
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> test = {5,7,7,8,8,10};
    vector<int> res = solution.searchRange(test, 6);
    for (int n : res) {
        cout << n << " ";
    }
}