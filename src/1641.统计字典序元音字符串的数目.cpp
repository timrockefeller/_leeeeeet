/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 *
 * https://leetcode-cn.com/problems/count-sorted-vowel-strings/description/
 *
 * algorithms
 * Medium (78.81%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 6.8K
 * Testcase Example:  '1'
 *
 * 给你一个整数 n，请返回长度为 n 、仅由元音 (a, e, i, o, u) 组成且按 字典序排列 的字符串数量。
 * 
 * 字符串 s 按 字典序排列 需要满足：对于所有有效的 i，s[i] 在字母表中的位置总是与 s[i+1] 相同或在 s[i+1] 之前。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 1
 * 输出：5
 * 解释：仅由元音组成的 5 个字典序字符串为 ["a","e","i","o","u"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 2
 * 输出：15
 * 解释：仅由元音组成的 15 个字典序字符串为
 * ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]
 * 注意，"ea" 不是符合题意的字符串，因为 'e' 在字母表中的位置比 'a' 靠后
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 33
 * 输出：66045
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 50 
 * 
 * 
 */
#include <memory>
using namespace std;
// @lc code=start
class Solution {
   public:
    int* dpr;

    int dp(int n, int p) {
        if (dpr == nullptr)
            return 0;
        if (dpr[n * 5 + p] != 0)
            return dpr[n * 5 + p];
        int ans = 0;
        for (int c = p; c < 5; c++) {
            ans += dp(n - 1, c);
        }
        return ans;
    }
    int countVowelStrings(int n) {
        dpr = new int[n * 5 + 1];
        dpr[0] = dpr[1] = dpr[2] = dpr[3] = dpr[4] = 1;
        memset(dpr + 5, 0, n * 20 - 16);
        int ans = dp(n, 0);
        delete[] dpr;
        return ans;
    }
    // int countVowelStrings(int n) {
    //     int n2 = n * n;
    //     return (n2 * n2 + 10 * n2 * n + 35 * n2 + 50 * n) / 24 + 1;
    // }
};
// @lc code=end
