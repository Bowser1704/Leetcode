/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int j = nums.size()-1;
        while(j>=1 && nums[j-1] >= nums[j])
            j--;
        // cout << j << endl;

        reverse(nums, j, nums.size());
        if(j == 0) return;

        int r = j;
        while(r < nums.size() && nums[r] <= nums[j-1])
            r++;
        swap(nums[j-1], nums[r]);
    }
    void reverse(vector<int>& nums, int start, int end){
        while(start < end) swap(nums[start++], nums[--end]);
    }
};
// @lc code=end

