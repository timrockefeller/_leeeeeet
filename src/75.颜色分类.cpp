/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (57.00%)
 * Likes:    732
 * Dislikes: 0
 * Total Accepted:    157.6K
 * Total Submissions: 276.5K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以不使用代码库中的排序函数来解决这道题吗？
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[0]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * nums[i] 为 0、1 或 2
 * 
 * 
 */
#include "default.h"
using namespace std;
// @lc code=start
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int lp = 0, rp = nums.size() - 1;
        for (int i = lp; i <= rp; i++) {
            while (nums[i] == 2 && i <= rp) {
                swap(nums[i], nums[rp--]);
            }
            if (nums[i] == 0)
                swap(nums[i], nums[lp++]);
        }
    }
};
// @lc code=end
