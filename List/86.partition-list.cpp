/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lList = new ListNode(-1);
        ListNode* lhead = lList;
        ListNode* geList = new ListNode(-1);
        ListNode* gHead = geList;
        while (head != nullptr) {
            if (head->val < x) {
                lList->next = head;
                lList = head;
            } else {
                geList->next = head;
                geList = head;
            }
            ListNode* temp = head->next;
            head->next = nullptr;
            head = temp;
        }
        lList->next = gHead->next;
        return lhead->next;
    }
};
// @lc code=end

