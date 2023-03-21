/*
 * @lc app=leetcode id=1871 lang=cpp
 *
 * [1871] Jump Game VII
 */

// @lc code=start
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), pre = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            if (i >= minJump)
                pre += dp[i - minJump];
            if (i > maxJump)
                pre -= dp[i - maxJump - 1];
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp[n - 1];
    }
};
// @lc code=end

