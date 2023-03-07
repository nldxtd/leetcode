/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        // 虚拟头结点
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        // 优先级队列，最小堆
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(
            [] (ListNode* a, ListNode* b) { return a->val > b->val; });
        // 将 k 个链表的头结点加入最小堆
        for (auto head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        while (!pq.empty()) {
            // 获取最小节点，接到结果链表中
            ListNode* node = pq.top();
            pq.pop();
            p->next = node;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
            // p 指针不断前进
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

