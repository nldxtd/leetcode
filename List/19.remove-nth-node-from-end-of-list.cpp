/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p1 = dummy;
        ListNode* p2 = dummy;
        while (n > -1) {
            p1 = p1->next;
            n--;
        }
        while (p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return dummy->next;
    }
};
// @lc code=end

