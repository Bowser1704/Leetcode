#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 *
 * https://leetcode-cn.com/problems/binary-subarrays-with-sum/description/
 *
 * algorithms
 * Medium (33.42%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    1.6K
 * Total Submissions: 4.8K
 * Testcase Example:  '[1,0,1,0,1]\n2'
 *
 * 在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：A = [1,0,1,0,1], S = 2
 * 输出：4
 * 解释：
 * 如下面黑体所示，有 4 个满足题目要求的子数组：
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * A.length <= 30000
 * 0 <= S <= A.length
 * A[i] 为 0 或 1
 * 
 * 
 */

// 考虑怎么用递归做。

// @lc code=start
// Your memory usage beats 5.48 % of cpp submissions (28.2 MB)
// what happen.
// 解法就是把1前后的0找出来 然后x*y。可以看做是一种排列。
class Solution {
   public:
    int findSum(int n) {
        return n * (n + 1) / 2;
    }
    int numSubarraysWithSum(vector<int>& A, int S) {
        int len = A.size();
        vector<int> site;
        for (int i = 0; i < len; i++) {
            if (A[i] == 1) {
                site.push_back(i);
            }
        }
        int siteLen = site.size();
        int result = 0;
        //考虑特殊情况0，仔细推理一下会发现只需要找到连续的0，并且每个连续n个0的数量为n*(n+1)/2，等差数列求和
        if (S == 0) {
            if (siteLen == 0) return findSum(len);
            result += findSum(site[0]);
            for (int i = 1; i < siteLen; i++) {
                result += findSum(site[i] - site[i - 1] - 1);
            }
            result += findSum(len - site[siteLen - 1] - 1);
            return result;
        }

        int start = 0, end = S - 1;
        while (end < siteLen) {
            int x = 0, y = 0;
            if (start > 0)
                x = site[start] - site[start - 1];
            else
                x = site[start] + 1;
            if (end < siteLen - 1)
                y = site[end + 1] - site[end];
            else
                y = len - site[end];
            result += x * y;
            start++;
            end++;
        }
        return result;
    }
};
// @lc code=end

//没有AC的暴力解法.
class ViloentSolution {
   public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int len = A.size(), result = 0;
        for (int i = 0; i < len; i++) {
            int sum = 0;
            for (int j = i; j < len; j++) {
                sum += A[j];
                if (sum == S) result++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> vec{0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    cout << solution.numSubarraysWithSum(vec, 0) << endl;
    // cout << solution.numSubarraysWithSum(vec, 2) << endl;
    // cout << solution.numSubarraysWithSum(vec, 1) << endl;
}