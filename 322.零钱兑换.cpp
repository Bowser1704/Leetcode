#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (37.75%)
 * Likes:    465
 * Dislikes: 0
 * Total Accepted:    57.4K
 * Total Submissions: 150.2K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */

// @lc code=start
class Solution {
   public:
    int ans;
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.rbegin(), coins.rend());
        ans = INT_MAX;
        coinChange(coins, amount, 0, 0);
        return ans == INT_MAX ? -1 : ans;
    }
    // cIndex 指向当前的索引， count 已选择个数
    void coinChange(vector<int>& coins, int amount, int cIndex, int count) {
        if (amount == 0) {
            // 只需要知道最少多少个，不在乎选了啥。
            ans = min(ans, count);
            return;
        }
        if (cIndex == coins.size()) return;
        // 选择了i个 coins[cIndex], count是已经选了多少个.
        for (int i = amount / coins[cIndex]; i >= 0 && i < ans - count; i--) {
            coinChange(coins, amount - i * coins[cIndex], cIndex + 1, count + i);
        }
    }
};
// @lc code=end


class BestSolution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = INT_MAX;
        sort(coins.begin(),coins.end());//将硬币从小到大排序
        helper(coins,amount,coins.size()-1,0,res);
        return res==INT_MAX?-1:res;
    }
    void helper(vector<int>& coins, int amount, int start,int cur, int& res){
        if(start<0) return;
        if(amount%coins[start]==0){
            res = min(res, cur+amount/coins[start]);
            return;
        }
        for(int i = amount/coins[start]; i >=0; i--){
            if(cur+i>=res-1)break;
            helper(coins,amount-i*coins[start],start-1,cur+i,res);
        }
    }
};