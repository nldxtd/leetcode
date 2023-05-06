/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    unordered_map<int, int> valToIndex;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            valToIndex[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1,
                    inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }

        // root 节点对应的值就是前序遍历数组的第一个元素
        int rootVal = preorder[preStart];
        // rootVal 在中序遍历数组中的索引
        int index = valToIndex[rootVal];

        int leftSize = index - inStart;

        // 先构造出当前根节点
        TreeNode* root = new TreeNode(rootVal);
        // 递归构造左右子树
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                        inorder, inStart, index - 1);

        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            inorder, index + 1, inEnd);
        return root;
    }
};
// @lc code=end

