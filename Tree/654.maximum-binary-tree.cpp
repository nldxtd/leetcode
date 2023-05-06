/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        auto max_it = max_element(nums.begin(), nums.end());
        int max_idx = distance(nums.begin(), max_it);
        TreeNode* root = new TreeNode(*max_it);
        // 递归调用构造左右子树
        if (max_idx > 0) {
            vector<int> left(nums.begin(), nums.begin() + max_idx);
            root->left = constructMaximumBinaryTree(left);
        }
        if (max_idx < nums.size() - 1) {
            vector<int> right(nums.begin() + max_idx + 1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};
// @lc code=end

