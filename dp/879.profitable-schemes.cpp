/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<long long>> dp(1+minProfit, vector<long long>(1+n, 0));
        dp[0][0] = 1;
        int mod = 1e9+7, len = group.size();
        for (int i = 0; i < len; i++) {
            for (int j = n; j >= group[i]; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    int newp = (k-profit[i] >= 0) ? k-profit[i] : 0;
                    dp[newp][j] = (dp[k][j-group[i]] + next[newp][j]) % mod;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = (ans+dp[minProfit][i]) % mod;
        }
        return ans;
    }
};
// @lc code=end

