#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
// another solution is left and right pointer.
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i , j, mid, cur, len = A.size();
        int res = 0;
        for (i = 0; i < len-1; i++) {
            j = i + 1;
            cur = i;
            if (A[cur] >= A[j]) {
                continue;
            }
            while(j < len-1 && A[cur] < A[j]) {
                cur++;
                j++;
            }
            mid = cur;
            while(j < len-1 && A[cur] > A[j]) {
                cur++;
                j++;
            }
            if(cur != mid)
                res = max(res, cur - i + 1);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> test = {2,2,2};
    int res = solution.longestMountain(test);
    cout << res << endl;
}