/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* a;
        ListNode* b;
        a = b = head;
        for (int i = 0; i < k; i++) {
            if (b == nullptr) return head;
            b = b->next;
        }
        ListNode* newhead = reserveBetween(a, b);
        a->next = reverseKGroup(b, k);
        return newhead;
    }

    ListNode* reserveBetween(ListNode* a, ListNode* b) {
        ListNode* pre = nullptr;
        ListNode* now = a;
        ListNode* nxt = a;
        while(now != b) {
            nxt = now->next;
            now->next = pre;
            pre = now;
            now = nxt;
        }
        return pre;
    }
};
// @lc code=end

