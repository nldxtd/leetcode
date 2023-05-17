/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode* head) {
        ListNode* ptr1 = head, * ptr2 = head;
        int ans = 0, count = 0;
        while(ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            count++;
        }
        vector<int> sum(count, 0);
        int i = 0;
        while (ptr1) {
            sum[i] += head->val;
            sum[count-i-1] += ptr1->val;
            ans = max(ans, max(sum[i], sum[count-i-1]));
            head = head->next;
            ptr1= ptr1->next;
            i++;
        }
        return ans;
    }
};
// @lc code=end

