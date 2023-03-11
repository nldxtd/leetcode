/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* lhead;
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        lhead = head;
        int len = 1;
        while (head->next != nullptr) {
            head = head->next;
            len++;
        }
        return buildTree(lhead, 0, len-1);
    }

    TreeNode* buildTree(ListNode* head, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left+right) / 2;
        int move = mid - left;
        ListNode* movep = head;
        while (move > 0) {
            movep = movep->next;
            move--;
        }
        TreeNode* node = new TreeNode(movep->val);
        node->left = buildTree(head, left, mid-1);
        node->right = buildTree(movep->next, mid+1, right);
        return node;
    }
};
// @lc code=end

