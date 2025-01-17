/*
 * @lc app=leetcode.cn id=42 lang=javascript
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (46.43%)
 * Likes:    582
 * Dislikes: 0
 * Total Accepted:    27.6K
 * Total Submissions: 59.4K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let earth = 0;
    let leftmax = 0;
    let rightmax = 0;
    let lefttotal = 0;
    let righttotal = 0;
    for (var i = 0; i < height.length; i++) { 
        earth += height[i];
        leftmax = Math.max(leftmax, height[i]);
        lefttotal += leftmax;
        rightmax = Math.max(rightmax, height[height.length - i - 1]);
        righttotal+=rightmax;
    }
    return - rightmax * height.length + lefttotal + righttotal - earth;

};

