/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if(!dp[i]) continue;
            for (auto &word : wordDict) {
                if(i + word.size() <= s.size() && s.substr(i, word.size()) == word)
                    dp[i+word.size()] = true;
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

