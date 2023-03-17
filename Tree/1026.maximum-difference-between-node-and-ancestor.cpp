/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
    int maxAncestorDiff(TreeNode* root) {
        return depthFirstSearch(root, root->val, root->val);
    }

    int depthFirstSearch(TreeNode* node, int max_val, int min_val) {
        if (node == nullptr) return max_val-min_val;
        else {
            max_val = max(max_val, node->val);
            min_val = min(min_val, node->val);
            int leftDiff = depthFirstSearch(node->left, max_val, min_val);
            int rightDiff = depthFirstSearch(node->right, max_val, min_val);   
            return max(leftDiff, rightDiff);
        }
    }
};
// @lc code=end

