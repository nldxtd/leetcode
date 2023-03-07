/*
 * @lc app=leetcode id=2187 lang=cpp
 *
 * [2187] Minimum Time to Complete Trips
 */
// @lc code=start
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long minTime = 0;
        long long maxTime = (long long) totalTrips * time[0];
        return calMinTime(time, minTime, maxTime, totalTrips);
    }

    long long calMinTime(vector<int>& time, long long mint, long long maxt, int totalTrips) {
        long long midt = (mint+maxt)/2;
        if (mint == midt) return maxt;
        long long count = 0;
        for (auto t : time) {
            count += midt / t;
        }
        if (count >= totalTrips) return calMinTime(time, mint, midt, totalTrips);
        else return calMinTime(time, midt, maxt, totalTrips);
    }
};
// @lc code=end

