/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (52.81%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 21.6K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。
 * 返回你可以获得的最大乘积。
 *
 * 示例 1:
 *
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 *
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 *
 */

// @lc code=start
#include <cmath>
class Solution {
   public:
    int integerBreak(int n) {
        if (n <= 3)
            return n - 1;
        int n3 = n / 3, r3 = n % 3;
        if (r3 == 1)
            return pow(3, n3 - 1) * 4;
        if (r3 == 0)
            return pow(3, n3);
        return pow(3, n3) * 2;
    }
};
// @lc code=end
