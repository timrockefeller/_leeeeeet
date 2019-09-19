/*
 * @lc app=leetcode.cn id=445 lang=cpp
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
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cmath>

class Solution {
   public:
    ListNode* step(ListNode* a, ListNode* b, int ac, int bc, int r) {
        if (r <= 1)
            return new ListNode(a->val + b->val);
        ListNode* n = step(ac > 0 ? a->next : a, bc > 0 ? b->next : b, ac + 1,
                           bc + 1, r - 1);
        ListNode* rs =
            new ListNode((n->val >= 10 ? 1 : 0) + (ac > 0 ? a->val : 0) +
                         (bc > 0 ? b->val : 0));
        n->val %= 10;
        rs->next = n;
        return rs;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len_a = 1, len_b = 1;
        ListNode *ca = l1, *cb = l2;
        do {
            if (ca->next != NULL) {
                len_a++;
                ca = ca->next;
            }
            if (cb->next != NULL) {
                len_b++;
                cb = cb->next;
            }
        } while (ca->next != NULL || cb->next != NULL);
        int len_r = std::max(len_a, len_b);
        ListNode* res = step(l1, l2, len_a - len_r, len_b - len_r, len_r + 1);
        while (res->val == 0 && res->next != NULL) {
            ListNode* tres = res;
            res = res->next;
            delete tres;
        }
        return res;
    }
};
