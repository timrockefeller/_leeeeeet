/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (63.54%)
 * Likes:    711
 * Dislikes: 0
 * Total Accepted:    222.8K
 * Total Submissions: 349.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> seqQueue;
        vector<vector<int>> rst;
        if (root != nullptr) {
            seqQueue.push(root);
            bfs(std::move(seqQueue), rst);
        }
        return rst;
    }
    void bfs(queue<TreeNode*>&& seqQueue, vector<vector<int>>& rst) {
        rst.push_back(vector<int>{});
        auto n = seqQueue.size();
        while (n-->0) {
            auto tmp = seqQueue.front();
            if (tmp) {
                rst.back().push_back(tmp->val);
                if (tmp->left != nullptr)
                    seqQueue.push(tmp->left);
                if (tmp->right != nullptr)
                    seqQueue.push(tmp->right);
                seqQueue.pop();
            }
        }
        if (!seqQueue.empty())
            bfs(std::move(seqQueue), rst);
    }
};
// @lc code=end
