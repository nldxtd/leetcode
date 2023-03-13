/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return checkTreeNode(root->left, root->right);
    }

    bool checkTreeNode(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) return true;
        else {
            if (leftNode == nullptr || rightNode == nullptr) return false;
            bool checkLeft = checkTreeNode(leftNode->left, rightNode->right);
            bool checkRight = checkTreeNode(leftNode->right, rightNode->left);
            return (checkLeft && checkRight && (leftNode->val == rightNode->val));
        }
    }
};
// @lc code=end

