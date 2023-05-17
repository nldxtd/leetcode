/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        ListNode* pos = ptr2->next;
        while (true) {
            pre->next = ptr2;
            ptr2->next = ptr1;
            ptr1->next = pos;
            if (!pos || !pos->next) break;
            pre = ptr1;
            ptr1 = pos;
            ptr2 = pos->next;
            pos = ptr2->next;
        }
        return dummyhead->next;
    }
};
// @lc code=end

