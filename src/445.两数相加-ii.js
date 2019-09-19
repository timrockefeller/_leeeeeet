/*
 * @lc app=leetcode.cn id=445 lang=javascript
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (51.01%)
 * Likes:    82
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 13.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
 * 
 * 
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 进阶:
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 示例:
 * 
 * 
 * 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出: 7 -> 8 -> 0 -> 7
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * 
 * @param {Number} ac 
 * @param {Number} bc 
 * @param {Number} r 
 * @returns {Node}
 */
var step = function (a, b, ac, bc, r) {
    if (r <= 1) return new ListNode(a.val + b.val);
    var n = step(ac > 0 ? a.next : a, bc > 0 ? b.next : b, ac + 1, bc + 1, r - 1);
    var carry = 0;
    if (n.val >= 10) {
        carry = 1;
        n.val -= 10;
    }
    var rs = new ListNode(carry + (ac > 0 ? a.val : 0) + (bc > 0 ? b.val : 0));
    rs.next = n;
    return rs;
};

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
        var length_a = 1, length_b = 1;
    var ca = l1, cb = l2;
    do {
        if (ca.next != null) { length_a++; ca = ca.next; }
        if (cb.next != null) { length_b++; cb = cb.next; }
    } while (ca.next != null || cb.next != null);
    var length_r = Math.max(length_a, length_b);
    var res = step(l1, l2, length_a - length_r, length_b - length_r, length_r + 1);
    while (res.val == 0 && res.next != null) {
        res = res.next;
    }
    return res;
};


