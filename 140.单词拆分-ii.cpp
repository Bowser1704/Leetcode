#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> map;
        return backtrace(s, map, wordDict);
    }
    vector<string> backtrace(string start, unordered_map<string, vector<string> >& map, vector<string>& wordDict) {
        if(map.count(start)) return map[start];
        if(start.empty()) return {""};
        vector<string> res;
        for (auto &word : wordDict) {
            // Firstly determine the beginning, calculate the back.
            if(start.substr(0, word.size()) != word) continue;
            vector<string> tmp = backtrace(start.substr(word.size()), map, wordDict);
            for (auto &t : tmp) {
                res.push_back(word+(t.empty()?"":" "+t));
            }
        }
        map[start] = res;
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<string> test = {"cat","cats","and","sand","dog"};
    vector<string> res = solution.wordBreak("catsanddog", test);
    for (auto &s : res) {
        cout << s << endl;
    }
}