/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (54.90%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    56.1K
 * Total Submissions: 101.2K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0
 * 移动到数组的末尾，同时保持非零元素的相对顺序。
 *
 * 示例:
 *
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 *
 * 说明:
 *
 *
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        //  p  k
        //  0  1  3  12  0  0
        int k = 0;  // point of iter
        int p = 0;  // point of first zero
        for (; k < nums.size(); k++) {
            // update p
            if(nums[k])
                nums[p++] = nums[k];
        }
        for (; p < nums.size(); p++) {
            nums[p] = 0;
        }
    }
};
