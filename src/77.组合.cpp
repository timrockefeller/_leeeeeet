/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (76.09%)
 * Likes:    453
 * Dislikes: 0
 * Total Accepted:    120.5K
 * Total Submissions: 158.3K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
#include "default.h"
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, tmp, n, k, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& tmp, int& n, int& k, int current) {
        // cout << k << " / " << tmp.size() << " : " << current << endl;
        // logvector(tmp);
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }

        for (int i = current + 1; i <= n; i++) {
            tmp.push_back(i);
            dfs(ans, tmp, n, k, i);
            tmp.pop_back();
        }
    }
    template <typename T>
    void logvector(vector<T>& tmp) {
        cout << "[";
        for (auto& obj : tmp) {
            cout << obj << ' ';
        }
        cout << "]" << endl;
    }
};
// @lc code=end
