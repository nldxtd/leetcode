/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
class Solution {
public:
    int ans;
    unordered_map<int, unordered_map<int, int>> graph;
    int minScore(int n, vector<vector<int>>& roads) {
        ans = 1e4;
        for (auto r : roads) {
            graph[r[0]][r[1]] = graph[r[1]][r[0]] = r[2];
        }
        vector<bool> visited(n, false);

        dfs(visited, 1);
        return ans;
    }
    void dfs(vector<bool>& visited, int now) {
        visited[now-1] = true;
        for (auto [des, len] : graph[now]) {
            if (len < ans) ans = len;
            if (!visited[des-1]) {
                dfs(visited, des);
            }
        }
    }
};
// @lc code=end

