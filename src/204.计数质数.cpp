/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (35.47%)
 * Likes:    459
 * Dislikes: 0
 * Total Accepted:    81.4K
 * Total Submissions: 229.4K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 0
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 1
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 5 * 10^6
 * 
 * 
 */
#include <math.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int countPrimes(int n) {
        int rsl = n >= 3 ? 1 : 0;
        for (int i = 3; i < n; i += 2) {
            bool ok = true;
            for (int j = 3; j <= sqrt(i); j++) {
                if (i / j * j == i) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                rsl++;
        }
        return rsl;
    }
    
};
// @lc code=end
