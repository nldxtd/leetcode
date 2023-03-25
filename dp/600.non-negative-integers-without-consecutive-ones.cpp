/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findIntegers(int n) {
        if(n < 3) return n + 1;
        vector<int> dp(32, 0);
        dp[0] = 2, dp[1] = 3;
        for(int i = 2; i < 32; i++) dp[i] = dp[i - 1] + dp[i - 2];
        int hbit = 31;
        while((n & (1 << hbit)) == 0) hbit--;
        return (n & (1 << (hbit - 1))) ? dp[hbit] : dp[hbit - 1] + findIntegers(n & ~(1 << hbit));
    }
};
// @lc code=end

