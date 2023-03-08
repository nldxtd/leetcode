/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *start, *end;
        if (fast == nullptr) {
            start = head;
            end = slow;
        } else {
            start = head;
            end = slow->next;
        }
        end = reverse(end);
        while (end != nullptr) {
            if (start->val == end->val) {
                start = start->next;
                end = end->next;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

