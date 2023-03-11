/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
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
    int len;
    ListNode* head;
    Solution(ListNode* head) {
        len = 1;
        this->head = head;
        while (head->next != nullptr) {
            head = head->next;
            len++;
        }
    }
    
    int getRandom() {
        int index = rand() % len;
        ListNode* p = head;
        while (index > 0) {
            p = p->next;
            index--;
        }
        return p->val;

    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

