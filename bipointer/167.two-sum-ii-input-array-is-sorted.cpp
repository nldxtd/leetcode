/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        vector<int> ans;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            } else {
                if (numbers[left]+numbers[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

