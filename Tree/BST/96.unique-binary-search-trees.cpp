/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> count(n+1, 0);
        count[0] = 1;
        count[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i-1; j++)
                count[i] += count[j]*count[i-j-1];
        }
        return count[n];
    }
};
// @lc code=end

