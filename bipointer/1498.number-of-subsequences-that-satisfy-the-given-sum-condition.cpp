/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
class Solution {
public:
    int numSubseq(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size(), l = 0, r = n - 1, mod = 1e9 + 7;
        vector<int> pows(n, 1);
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        while (l <= r) {
            if (A[l] + A[r] > target) {
                r--;
            } else {
                res = (res + pows[r - l++]) % mod;
            }
        }
        return res;
    }
};
// @lc code=end

