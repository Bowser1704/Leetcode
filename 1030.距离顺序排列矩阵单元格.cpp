#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        unordered_set<tuple<int, int>> visited;
        int i = r0, j = c0;
        add2ans(visited, ans, i, j, R, C);
        return ans;
    }
    void add2ans(unordered_set<tuple<int, int>>& visited, vector<vector<int>>& ans, int i, int j, int R, int C) {
        if(i<0 || i>=R || j<0 || j>=C) return;
        auto temp = make_tuple(i, j);
        if(visited.find(temp) != visited.end())
            return;
        else
            visited.insert(temp);
        ans.push_back(vector<int>(i,j));
        add2ans(visited, ans, i-1, j, R, C);
        add2ans(visited,ans, i+1, j, R, C);
        add2ans(visited,ans, i, j+1, R, C);
        add2ans(visited, ans, i, j-1, R, C);
        return;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<int>> ans = solution.allCellsDistOrder(1,2,0,0);
    // cout << solution.numSubarraysWithSum(vec, 2) << endl;
    // cout << solution.numSubarraysWithSum(vec, 1) << endl;
}