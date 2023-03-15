/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg_count = 0, min = INT_MAX;
        long long sum = 0;
        for (auto row : matrix) {
            for (auto num : row) {
                if (num < 0) neg_count += 1;
                sum += abs(num);
                if (abs(num) < min) min = abs(num);
            }
        }
        if (neg_count % 2 == 1) {
            sum -= 2*min;
        }
        return sum;
    }
};
// @lc code=end

