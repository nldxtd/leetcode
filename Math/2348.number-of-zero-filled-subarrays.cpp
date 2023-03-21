/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 */

// @lc code=start
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                while (i < nums.size() && nums[i] == 0) {
                    i++;
                    count++;
                }
                ans += (count+1) * count / 2;
                count = 0;
                i--;
            }
        }
        return ans;
    }
};
// @lc code=end

