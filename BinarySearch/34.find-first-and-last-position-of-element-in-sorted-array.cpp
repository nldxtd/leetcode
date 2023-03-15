/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int sleft = searchLeft(nums, target, left, right);
        int sright = searchRight(nums, target, left, right);
        return vector<int> {sleft, sright};
    }

    int searchLeft(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] > target) right = mid-1;
            else if(nums[mid] < target) left = mid+1;
            else {
                right = mid-1;
            } 
        }
        if (left >= nums.size()) return -1;
        return (nums[left] == target) ? left : -1;
    }

    int searchRight(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] > target) right = mid-1;
            else if(nums[mid] < target) left = mid+1;
            else {
                left = mid+1;
            } 
        }
        if (left-1 >= nums.size()) return -1;
        return (nums[left-1] == target) ? left-1 : -1;
    }
};
// @lc code=end

