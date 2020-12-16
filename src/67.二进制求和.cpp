/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (54.35%)
 * Likes:    530
 * Dislikes: 0
 * Total Accepted:    140.1K
 * Total Submissions: 257.8K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */
#include "default.h"
using namespace std;
// @lc code=start
class Solution {
   public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        bool carry = false;
        auto getChar = [](string& c, int i) { return i < c.size() ? c.at(i) - '0' : 0; };
        for (int i = 0; i < a.size() || i < b.size(); i++) {
            int cur = getChar(a, i) + getChar(b, i) + (carry ? 1 : 0);
            carry = cur > 1;
            ans.push_back('0' + (cur % 2));
        }
        if (carry)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
