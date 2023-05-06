/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
    if (root == nullptr) return nullptr;
    // 遍历「三叉树」，连接相邻节点
    traverse(root->left, root->right);
    return root;
}

// 三叉树遍历框架
void traverse(Node* node1, Node* node2) {
    if (node1 == nullptr || node2 == nullptr) {
        return;
    }
    /**** 前序位置 ****/
    // 将传入的两个节点穿起来
    node1->next = node2;
    
    // 连接相同父节点的两个子节点
    traverse(node1->left, node1->right);
    traverse(node2->left, node2->right);
    // 连接跨越父节点的两个子节点
    traverse(node1->right, node2->left);
}
};
// @lc code=end

