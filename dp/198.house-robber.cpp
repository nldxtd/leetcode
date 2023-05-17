/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(len+2, 0);
        for (int i = len-1; i >= 0; i--) count[i] = max(count[i+1], count[i+2]+nums[i]);
        return count[0];
    }
};
// @lc code=end

