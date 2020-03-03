#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.23%)
 * Likes:    382
 * Dislikes: 0
 * Total Accepted:    84.1K
 * Total Submissions: 137.3K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// 库函数就是比你写的快。
// @lc code=start
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res =  *(nums.end() - k);
        return res;
    }
};
// @lc code=end


class PartitionSolution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int begin = 0, end = nums.size();
        int pos = 0;
        while (begin < end) {
            pos = partition(nums, begin, end);
            if (pos == k - 1) {
                break;
            } else if (pos < k - 1) {
                begin = pos + 1;
            } else {
                end = pos;
            }
        }
        return nums[pos];
    }

    // [lo, hi)
    int partition(vector<int>& nums, int lo, int hi) {
        int pivot = nums[lo];
        while (lo < hi) {
            while (lo < hi && nums[--hi] <= pivot)
                ;
            nums[lo] = nums[hi];
            while (lo < hi && nums[++lo] >= pivot)
                ;
            nums[hi] = nums[lo];
        }
        nums[lo] = pivot;
        return lo;
    }
};

int main() {
    Solution solution;
    vector<int> vec{3, 2, 1, 5, 6, 4};
    cout << solution.findKthLargest(vec, 2) << endl;
    // cout << solution.numSubarraysWithSum(vec, 2) << endl;
    // cout << solution.numSubarraysWithSum(vec, 1) << endl;
}