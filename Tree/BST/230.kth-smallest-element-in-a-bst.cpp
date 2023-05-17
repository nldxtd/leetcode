/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 利用 BST 的中序遍历特性
        traverse(root, k, res, rank);
        return res;
    }

    int res = 0;
    int rank = 0;

    void traverse(TreeNode* root, int k, int& res, int& rank) {
        if (!root) {
            return;
        }
        traverse(root->left, k, res, rank);
        /* 中序遍历代码位置 */
        rank++;
        if (k == rank) {
            // 找到第 k 小的元素
            res = root->val;
            return;
        }
        traverse(root->right, k, res, rank);
    }
};
// @lc code=end

