/*
 * @lc app=leetcode.cn id=48 lang=javascript
 *
 * [48] 旋转图像
 *
 * https://leetcode-cn.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (64.36%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    35.4K
 * Total Submissions: 55K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵表示一个图像。
 * 
 * 将图像顺时针旋转 90 度。
 * 
 * 说明：
 * 
 * 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 * 
 * 示例 1:
 * 
 * 给定 matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 给定 matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    if (matrix.length == 1) return;
    const las = matrix.length - 1;
    const mid = matrix.length / 2;
    for (var i = 0; i < mid; i++) {
        for (var j = i; j < las - i; j++) {
            swap(matrix, i, j, j, las - i);
            swap(matrix, i, j, las - j, i);
            swap(matrix, las - j, i, las - i, las - j);
        }
    }
};

var swap = function (matrix, x1, y1, x2, y2) {
    var t = matrix[x1][y1];
    matrix[x1][y1] = matrix[x2][y2];
    matrix[x2][y2] = t;
};

