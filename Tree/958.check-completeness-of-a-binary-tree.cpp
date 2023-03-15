/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
    int max_height = 0;
    bool passed = false;
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        return checkNode(root, 1);
    }

    bool checkNode(TreeNode* node, int height) {
        if (node->left != nullptr && node->right != nullptr) {
            return checkNode(node->left, height+1) && checkNode(node->right, height+1);
        } else if (node->left == nullptr && node->right == nullptr) {
            if (!max_height) {
                max_height = height;
                return true;
            } else {
                if (!passed && (height == max_height-1)) {
                    passed = true;
                }
                return ((passed && (height == max_height-1)) || (!passed && (height == max_height)));
            }
        } else if (node->left != nullptr && node->right == nullptr) {
            bool left_match = checkNode(node->left, height+1);
            if (height < max_height-1) return false; 
            passed = true; 
            return left_match;
        } else {
            return false;
        }
        return true;
    }
};
// @lc code=end

