/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 *
 * https://leetcode-cn.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (46.08%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 7.7K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 在计算机界中，我们总是追求用有限的资源获取最大的收益。
 *
 * 现在，假设你分别支配着 m 个 0 和 n
 * 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
 *
 * 你的任务是使用给定的 m 个 0 和 n
 * 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。
 *
 * 注意:
 *
 *
 * 给定 0 和 1 的数量都不会超过 100。
 * 给定字符串数组的长度不会超过 600。
 *
 *
 * 示例 1:
 *
 *
 * 输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * 输出: 4
 *
 * 解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0"
 * 。
 *
 *
 * 示例 2:
 *
 *
 * 输入: Array = {"10", "0", "1"}, m = 1, n = 1
 * 输出: 2
 *
 * 解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
 *
 *
 *  #遍历可容纳的背包 */

// @lc code=start

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    int dpr[101][101] = {0};

   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.size()==0)
            return 0;
        for (int s = 0; s < strs.size(); s++) {
            int c0 = count(strs[s].begin(), strs[s].end(), '0'),
                c1 = count(strs[s].begin(), strs[s].end(), '1');
            for (int i = m; i > c0 - 1; i--) {
                for (int j = n; j > c1 - 1; j--) {
                    dpr[i][j] = max(dpr[i][j], dpr[i - c0][j - c1] + 1);
                }
            }
        }
        return dpr[m][n];
    }
    // int dp(vector<string>& strs, int m, int n) {
    //     return max(dp(strs, m, n),dp(strs,m-));
    // }
};
// @lc code=end
