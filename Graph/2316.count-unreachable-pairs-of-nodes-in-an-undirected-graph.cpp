/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */

// @lc code=start
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        long long ans = (long long)n*(n-1) / 2;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long cnt = 0;
                dfs(i, graph, cnt, visited);
                ans -= cnt*(cnt-1)/2;
            }
        }
        return ans;
    }
    void dfs(int node, unordered_map<int,vector<int>>& m, long long& cnt, vector<int>& vis){
        vis[node] = 1;
        cnt++;
        for(auto& i: m[node]){
            if(vis[i]==0) dfs(i,m,cnt,vis);   
        }
    }
};
// @lc code=end

