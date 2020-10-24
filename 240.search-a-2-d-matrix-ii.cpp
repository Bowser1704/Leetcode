#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n, m;
        if ( (n = matrix.size()) && (m = matrix[0].size()) ) {
            int i = n - 1, j = 0; // i decreasing, j increasing.
            while (i >= 0 && j < m) {
                if (matrix[i][j] == target)
                    return true;
                else if (matrix[i][j] < target)
                    j++;
                else
                    i--;
            }
        }
        return false;
    }
};
// @lc code=end

