/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution {
    void add(long &a, long &b) { a = (a + b) % ((int) 1e9+7); }
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        // ask for (m+1)*(n+1) space for simpler process
        vector<vector<int>> cnt(m + 1, vector<int>(n + 1));
        for (int i = m - 1; i >= 0; --i) {
            int s = 0;
            for (int j = n - 1; j >= 0; --j) {
                s += pizza[i][j] == 'A';
                cnt[i][j] = cnt[i + 1][j] + s;
            }
        }
        vector<vector<vector<long>>> dp(m + 1, vector<vector<long>>(n + 1, vector<long>(k + 1)));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j][1] = cnt[i][j] > 0;
                for (int _k = 2; _k <= k; ++_k) {
                    for (int t = i + 1; t < m; ++t) {
                        if (cnt[i][j] == cnt[t][j]) continue;
                        if (cnt[t][j] == 0) break;
                        add(dp[i][j][_k], dp[t][j][_k - 1]);
                    }
                    for (int t = j + 1; t < n; ++t) {
                        if (cnt[i][j] == cnt[i][t]) continue;
                        if (cnt[i][t] == 0) break;
                        add(dp[i][j][_k], dp[i][t][_k - 1]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};
// @lc code=end

