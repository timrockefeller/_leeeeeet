/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (70.65%)
 * Likes:    439
 * Dislikes: 0
 * Total Accepted:    30.2K
 * Total Submissions: 42.5K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
#include "default.h"
using namespace std;
// @lc code=start
class Solution {
   public:
    void gen(vector<string>& ans, string& tmp, int open, int close, int& n) {
        if (close == n) {
            ans.push_back(tmp);
            return;
        }
        if (open < n) {
            tmp.push_back('(');
            gen(ans, tmp, open + 1, close, n);
            tmp.pop_back();
        }
        if (close < open) {
            tmp.push_back(')');
            gen(ans, tmp, open, close + 1, n);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        gen(ans, tmp, 0, 0, n);
        return ans;
    }
};
// @lc code=end
