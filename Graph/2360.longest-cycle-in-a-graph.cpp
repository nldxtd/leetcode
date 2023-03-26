/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 */

// @lc code=start
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int size = edges.size(), ans = -1, cnt = 1;
        vector<int> visited(size, 0);
        vector<int> index(size, 0);
        for (int i = 0; i < size; i++) {
            if (visited[i])
                continue;
            int now = i, start = cnt;
            while (now != -1 && !visited[now]) {
                visited[now] = 1;
                index[now] = cnt;
                cnt++;
                now = edges[now];
            }
            if (now != -1 && index[now] >= start) 
                ans = max(ans, cnt-index[now]);
        }
        return ans;
    }
};
// @lc code=end

