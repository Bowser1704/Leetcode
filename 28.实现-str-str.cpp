#include <iostream>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.13%)
 * Likes:    326
 * Dislikes: 0
 * Total Accepted:    109.2K
 * Total Submissions: 278.8K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++) {
            bool isValid = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) return i;
        }
        return -1;
    }
};
// @lc code=end

class BFSolution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++) {
            bool isValid = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) return i;
        }
        return -1;
    }
};

class KMPSolution {
   public:
    //前缀函数数组的创建。
    void preFunction(string needle, int* pst) {
        int n = needle.size();
        for (int i = 1; i < n; i++) {
            int j = pst[i - 1];
            while (j > 0 && needle[i] != needle[j]) j = pst[j - 1];
            if (needle[i] == needle[j]) j++;
            pst[i] = j;
        }
    }
};

//未完成， 太复杂了吧。
class BMSolution {
   private:
    static const int SIZE = 256;
    void generateHT(string& needle, int* ht) {
        for (int i = 0; i < SIZE; i++) {
            ht[i] = -1;
        }
        int n = needle.size();
        //这样做的话，实际上相当于逆序，后面的值会覆盖前面的。
        for (int i = 0; i < n; i++) {
            int ascii = (int)needle[i];     //ascii码
            ht[ascii] = i;
        }
    }

   public:
    int strStr(string haystack, string needle) {
        int ht[SIZE];
        generateHT(needle, ht);
        int i = 0, n = haystack.size(), m = needle.size();
        while (i <= n - m) {
            //j 是模式串下标
            int j;
            for (j = m - 1; i >= 0; j--) {
                //主串中坏字符对应的是 i+模式串下标j 即为si
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            //如果 j小于0，就已经成功了。
            if (j < 0) {
                return i;
            }
            //ht即 坏字符最后一次的位置 即为xi。
            i = i + (j - ht[(int)haystack[i + j]]);  //模式串向后移动
        }
        return -1;
    }
};