/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
class Solution {
public:
    vector<int> diff;
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        diff = vector<int>(n+1, 0);
        for(auto booking : bookings) {
            diff[booking[0]-1] += booking[2];
            diff[booking[1]] -= booking[2];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += diff[i];
            diff[i] = count;
        }
        diff.pop_back();
        return diff;
    }
};
// @lc code=end

