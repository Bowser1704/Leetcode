#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.16%)
 * Likes:    1233
 * Dislikes: 0
 * Total Accepted:    163.9K
 * Total Submissions: 408.1K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        if (s == "") return true;
        if (s.length() % 2 != 0) return false;
        stack<char> charstack;
        for (char ch :s) {
            switch(ch) {
                case '{':
                case '[':
                case '(':charstack.push(ch); break;
                case ')':if(charstack.empty() || charstack.top() != '(') return false; else charstack.pop(); break;
                case '}':if(charstack.empty() || charstack.top() != '{') return false; else charstack.pop(); break;
                case ']':if(charstack.empty() || charstack.top() != '[') return false; else charstack.pop(); break;
                default: ;
            }
        }
        return charstack.empty();
    }
};
// @lc code=end


class UglySolution {
   public:
    bool isValid(string s) {
        if (s == "") return true;
        if (s.length() % 2 != 0) return false;
        stack<char> tempstack;
        int i = 0;
        while (i < s.length()) {
            char ch = s[i++];
            if (ch == '[' || ch == '{' || ch == '(') {
                tempstack.push(ch);
            } else if (!tempstack.empty()) {
                if ((ch == ']' && tempstack.top() == '[') || (ch == '}' && tempstack.top() == '{') || (ch == ')' && tempstack.top() == '(')) {
                    tempstack.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        if (tempstack.empty()) return true;
        return false;
    }
};

int main() {
    Solution solution;
    std::cout << solution.isValid("()()") << std::endl;
}