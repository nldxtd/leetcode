/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        for (auto num : nums) {
            if (num == 0) return 0;
            if (num < 0) count += 1;
        }
        return (count % 2) == 0 ? 1 : -1;
    }
};
// @lc code=end

