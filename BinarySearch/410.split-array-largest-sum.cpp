/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums, int k, int curr) {
        int i=-1, n = nums.size(), count=1;
        int sum=0;
        while(++i<n && count<=k){
            if(sum+nums[i] <= curr) sum += nums[i];  
            else sum=nums[i], count++;
        }
        return count<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0, mid, ans;
        for (int num : nums) {
            left = max(left, num);
            right += num;
        }
        ans = right;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (check(nums, k, mid)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
};
// @lc code=end

