/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    vector<int> diff;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        diff = vector<int>(1001, 0);
        for (auto trip : trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }
        int count = 0;
        for (auto d : diff) {
            count += d;
            if (count > capacity) return false;
        }
        return true;
    }
};
// @lc code=end

