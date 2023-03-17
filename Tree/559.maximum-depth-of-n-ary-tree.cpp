/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        return searchNode(root);
    }

    int searchNode(Node* node) {
        if (node == nullptr) return 0;
        if (node->children.size() == 0) {
            return 1;
        }
        int height = 0;
        for (auto child : node->children) {
            int cheight = searchNode(child);
            height = max(cheight, height);
        }
        return height+1;
    }
};
// @lc code=end

