/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (55.93%)
 * Likes:    599
 * Dislikes: 0
 * Total Accepted:    110.3K
 * Total Submissions: 197K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 示例 1:
 *
 * 输入: 121
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 *
 *
 * 示例 3:
 *
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 *
 *
 * 进阶:
 *
 * 你能不将整数转为字符串来解决这个问题吗？
 *
 */

#include<cmath>

class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) 
            return false;
        int count = (int)log10(x)+1; 
        while(count>1){
            if(x%10 != (int)(x/pow(10,count-1)))
                return false;
            x = ((x - x % 10) / 10) % ((int)pow(10, count - 2));
            count -= 2;
        }
        return true;
    }
};
