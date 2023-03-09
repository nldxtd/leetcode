/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head;
        while (right != nullptr && right->next != nullptr) {
            right = right->next;
            if (left->val != right->val) {
                left->next = right;
                left = right;
            }
        }
        if (left != nullptr && left->val == right->val) {
            left->next = nullptr;
        }
        return head;
    }
};
// @lc code=end

