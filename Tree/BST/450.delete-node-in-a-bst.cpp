/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if (root->val == key) {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            // 当节点有两个子节点时，用其右子树最小的节点代替该节点
            TreeNode* minNode = findMin(root->right);
            root->right = deleteNode(root->right, minNode->val);
            minNode->left = root->left;
            minNode->right = root->right;
            root = minNode;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else { 
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
};
// @lc code=end

