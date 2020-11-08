/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        queue<string> q;
        unordered_set<string> visited, dead(deadends.begin(), deadends.end());
        q.push(start);
        visited.insert(start);
        int depth = 0;
        while(!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                if(cur == target) return depth;
                if(dead.find(cur) != dead.end()) continue;
                for(auto &ch : cur) {
                    char temp = ch;
                    if(ch == '9') ch = '0';
                    else ch++;
                    if(visited.find(cur) == visited.end()){
                        q.push(cur);
                        visited.insert(cur);
                        cout << cur << endl;
                    }
                    ch = temp;
                    if(ch == '0') ch = '9';
                    else ch--;
                    if(visited.find(cur) == visited.end()){
                        q.push(cur);
                        visited.insert(cur);
                        cout << cur << endl;
                    }
                    ch = temp;
                }
            }
            depth++;
        }
        return -1;
    }
};
// @lc code=end

