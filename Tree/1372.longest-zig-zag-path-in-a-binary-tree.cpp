/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
    int ans;
public:
    int longestZigZag(TreeNode* root) {
        ans = 0;
        search(root->left, 0, 0);
        search(root->right, 1, 0);
        return ans;
    }

    void search(TreeNode* node, int dir, int len) {
        if (node == nullptr) {
            if (len > ans) ans = len;
            return;
        }
        if (dir == 0) {
            search(node->left, 0, 0);
            search(node->right, 1, len+1);
        } else {
            search(node->left, 0, len+1);
            search(node->right, 1, 0);
        }
    }
};
// @lc code=end

