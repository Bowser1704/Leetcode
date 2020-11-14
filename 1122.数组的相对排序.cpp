#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, vector<int>> pos;
        unordered_set<int> arr2set(arr2.begin(), arr2.end());
        int size1 = arr1.size(), size2 = arr2.size();
        vector<int> res1, res2;
        for(int i=0; i<size1; i++) {
            if(arr2set.find(arr1[i]) == arr2set.end())
                res2.push_back(arr1[i]);
            else {
                if(pos.find(arr1[i]) == pos.end())
                    pos[arr1[i]] = vector<int>();
                pos[arr1[i]].push_back(i);
            }
        }
        sort(res2.begin(), res2.end());
        int cur = 0;
        for(int i=0; i<size2; i++) {
            for(auto j : pos[arr2[i]]) {
                res1.push_back(arr1[j]);
                cur++;
            }
        }
        res1.insert(res1.end(), res2.begin(), res2.end());
        return res1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    solution.relativeSortArray(arr1, arr2);
}
