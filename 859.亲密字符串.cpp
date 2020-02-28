#include <iostream>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 *
 * https://leetcode-cn.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (27.24%)
 * Likes:    59
 * Dislikes: 0
 * Total Accepted:    7.6K
 * Total Submissions: 27.9K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * 给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入： A = "ab", B = "ba"
 * 输出： true
 * 
 * 
 * 示例 2：
 * 
 * 输入： A = "ab", B = "ab"
 * 输出： false
 * 
 * 
 * 示例 3:
 * 
 * 输入： A = "aa", B = "aa"
 * 输出： true
 * 
 * 
 * 示例 4：
 * 
 * 输入： A = "aaaaaaabc", B = "aaaaaaacb"
 * 输出： true
 * 
 * 
 * 示例 5：
 * 
 * 输入： A = "", B = "aa"
 * 输出： false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A 和 B 仅由小写字母构成。
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        int len = A.length();
        //A == B 这种情况需要找到两个一样的字符，也就是存在i,j使得A[i] == A[j]，同理B中也是一样。
        //A != B 这种情况的话，就是A，B中两个元素交换一下就相等了。也就是A[i] == B[i] && B[i] == A[j]
        if (A == B) {
            //wtm leetcode上面不可以直接用new，new一个数组aa，dd，都是错的，不晓得什么原因。
            int count[26] = {0};
            for (int i = 0; i < len; i++) {
                count[A[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (count[i] > 1) return true;
            }
            return false;
        } else {
            int first = -1, second = -1;
            for (int i = 0; i < len; i++) {
                //找到两个数就够了，i，j
                if (A[i] != B[i]) {
                    if (first == -1) {
                        first = i;
                    } else if (second == -1) {
                        second = i;
                    } else
                        return false;
                }
            }
            return second != -1 && A[first] == B[second] && A[second] == B[first];
        }
        return true;
    }
};
// @lc code=end

//Firstly, I have no idea.
int main() {
    Solution solution;
    cout << solution.buddyStrings("aa", "aa");
}