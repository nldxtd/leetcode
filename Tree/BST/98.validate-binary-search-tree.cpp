/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

    // 限定以 root 为根的子树节点必须满足 max->val > root->val > min->val
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        // base case
        if (root == nullptr) return true;
        // 若 root->val 不符合 max 和 min 的限制，说明不是合法 BST
        if (min != nullptr && root->val <= min->val) return false;   
        if (max != nullptr && root->val >= max->val) return false;
        // 限定左子树的最大值是 root->val，右子树的最小值是 root->val
        return isValidBST(root->left, min, root) 
            && isValidBST(root->right, root, max);
    }
};
// @lc code=end

