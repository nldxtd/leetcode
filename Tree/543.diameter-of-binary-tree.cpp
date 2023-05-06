/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    // 记录最大直径的长度
    int maxDiameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // 对每个节点计算直径，求最大直径
        traverse(root);
        return maxDiameter;
    }

    // 遍历二叉树
    int traverse(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftMax = traverse(root->left);
        int rightMax = traverse(root->right);
        int myDiameter = leftMax + rightMax;
        // 更新全局最大直径
        maxDiameter = max(maxDiameter, myDiameter);
        return max(leftMax, rightMax)+1;
    }
};
// @lc code=end

