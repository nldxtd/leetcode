/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 */

// @lc code=start
class Solution {
public:
    bool isNeighbor(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                if (++diff > 2) return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++)
            for (int j = i+1; j < n; j++) {
                if (isNeighbor(strs[i], strs[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        vector<bool> v(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == false) {
                dfs(g, v, i);
                ans++; // connected group count
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& g, vector<bool>& v, int x) {
        v[x] = true;
        for (int adj: g[x])
            if (v[adj] == false)
                dfs(g, v, adj);
    } 
};
// @lc code=end

