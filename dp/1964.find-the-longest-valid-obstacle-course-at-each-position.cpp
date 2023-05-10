/*
 * @lc app=leetcode id=1964 lang=cpp
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
 */

// @lc code=start
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> dp (obstacles.size(),1);
        int result=1;
        vector<int> b(obstacles.size()+1, INT_MAX);
        b[0]=INT_MIN;
       
        for(int i=0; i<obstacles.size(); i++){
            auto k = upper_bound(b.begin(), b.end(), obstacles[i]) - b.begin();
            b[k] = obstacles[i];
            dp[i]=k;
        }
        return dp;
    }
};
// @lc code=end

