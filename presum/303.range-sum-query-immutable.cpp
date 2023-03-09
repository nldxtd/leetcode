/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
public:
    vector<int> presum;
    NumArray(vector<int>& nums) {
        int sum = 0;
        presum.push_back(sum);
        for (int num : nums) {
            sum += num;
            presum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return presum[right+1]-presum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

