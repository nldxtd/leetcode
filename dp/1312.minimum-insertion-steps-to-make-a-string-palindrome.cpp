/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = len-2; i >= 0; i--) {
            for (int j = i+1; j < len; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = min(dp[i][j-1], dp[i+1][j])+1;
            }
        }
        return dp[0][len-1];
    }
};
// @lc code=end

