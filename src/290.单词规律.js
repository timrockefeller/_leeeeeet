/*
 * @lc app=leetcode.cn id=290 lang=javascript
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (39.38%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 22.3K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function (pattern, str) {
    var map = [],pam = [];
    var strs = str.split(" ");
    if (pattern.length != strs.length) {
        return false;
    }
    for (let ip = 0; ip < pattern.length; ip++) {
        var p = pattern[ip];
        if (map[p] == undefined && pam[strs[ip]] == undefined) {
            map[p] = strs[ip];
            pam[strs[ip]] = p;
            continue;
        } else if (map[p] != strs[ip] || pam[strs[ip]] != p) {
            return false;
        }
    }
    return true;
};


// function main() {
//     console.info(wordPattern("abba", "dog cat cat fish") + ":flase");
//     console.info(wordPattern("abba", "dog cat cat dog") + ":true");
// }
// main();
