/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<int, Node*>& mp) {
        vector<Node*> neighbour;
        Node* clone = new Node(cur->val);
        mp[cur->val]=clone;
        for(auto it : cur->neighbors) {
            if(mp.find(it->val) != mp.end())
                neighbour.push_back(mp[it->val]);    //directly push back the clone node from map to neigh
            else
                neighbour.push_back(dfs(it, mp));
        }
        clone->neighbors = neighbour;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> mp;
        if(!node) return nullptr;
        return dfs(node, mp);
    }
};
// @lc code=end

