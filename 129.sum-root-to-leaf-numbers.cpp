/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return sum;
        else {
            traverse(root, 0);
            return sum;
        }
    }

    void traverse(TreeNode* node, int pre) {
        pre = pre*10 + node->val;
        if (node->left == nullptr && node->right == nullptr)
            sum += pre;
        else {
            if (node->left != nullptr) traverse(node->left, pre);
            if (node->right != nullptr) traverse(node->right, pre);
        }
    }
};
// @lc code=end

