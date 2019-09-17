/*
 * @lc app=leetcode.cn id=14 lang=javascript
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.79%)
 * Likes:    700
 * Dislikes: 0
 * Total Accepted:    122.8K
 * Total Submissions: 352.9K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    if (strs.length == 0) return "";
    var cur = 0;
    while (cpm(strs, cur++)) {}
    return strs[0].substr(0, cur-1);
};
var cpm = function (strs, cur) {
    if (strs[0][cur] == undefined) return false;
    var char = strs[0][cur];
    for (var c in strs) {
        if (strs[c][cur] != char)
            return false;
    }
    return true;
};
