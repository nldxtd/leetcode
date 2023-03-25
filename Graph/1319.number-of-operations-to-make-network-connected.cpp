/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        int father[n];
        iota(father, father+n, 0);
        for (auto c : connections) {
            int left = c[0], right = c[1];
            while (left != father[left]) {
                left = father[left];
            }
            while (right != father[right]) {
                right = father[right];
            }
            father[max(left, right)] = min(left, right);
        }
        unordered_set<int> father_set;
        for (int i = 0; i < n; i++) {
            int now = i;
            while(now != father[now]) {
                now = father[now];
            }
            father_set.insert(now);
        }
        return father_set.size()-1;
    }
};
// @lc code=end

