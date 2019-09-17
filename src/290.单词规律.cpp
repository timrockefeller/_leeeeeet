/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (39.38%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 22.3K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 *
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 *
 * 示例1:
 *
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 *
 * 示例 2:
 *
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 *
 * 示例 3:
 *
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 *
 * 示例 4:
 *
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 *
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 *
 */

#include<string>
#include <vector>
#include<map>
using namespace std;
bool
wordPattern(string pattern, string str) {
    vector<string> lis1;
    int pos;
    int i = 0;
    while (pos != -1) {
        pos = str.find_first_of(' ', i);
        string temp = str.substr(i, pos - i);
        lis1.push_back(temp);
        i = pos + 1;
    }
    if (pattern.size() != lis1.size())
        return false;
    map<char, string> s;
    map<string, char> s1;
    for (int i = 0; i < lis1.size(); i++) {
        if (s.find(pattern[i]) != s.end()) {
            if (s[pattern[i]] != lis1[i])
                return false;
        } else {
            s[pattern[i]] = lis1[i];
        }
        if (s1.find(lis1[i]) != s1.end()) {
            if (s1[lis1[i]] != pattern[i])
                return false;
        } else {
            s1[lis1[i]] = pattern[i];
        }
    }
    return true;
}
