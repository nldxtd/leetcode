/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
class Solution {
    int lower, upper;
    long long* presum;
    long long* temp;
    int count;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        presum = new long long[nums.size()+1];
        temp = new long long[nums.size()+1];
        presum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum[i+1] = presum[i] + nums[i];
        }
        sort(presum, 0, nums.size());
        return count;
    }

    void sort(long long* presum, int lo, int hi) {
        if (lo == hi) return;
        int mi = lo+(hi-lo)/2;
        sort(presum, lo, mi);
        sort(presum, mi+1, hi);
        merge(presum, lo, mi, hi);
    }

    void merge(long long* presum, int lo, int mi, int hi) {
        for (int i = lo; i <= hi; i++) {
            temp[i] = presum[i];
        }
        
        // 进行效率优化
        // 维护左闭右开区间 [start, end) 中的元素和 nums[i] 的差在 [lower, upper] 中
        int start=mi+1, end=mi+1;
        for (int i = lo; i <= mi; i++) {
            // 如果 nums[i] 对应的区间是 [start, end)，
            // 那么 nums[i+1] 对应的区间一定会整体右移，类似滑动窗口
            while (start <= hi && presum[start] - presum[i] < lower) {
                start++;
            }
            while (end <= hi && presum[end] - presum[i] <= upper) {
                end++;
            }
            count += end-start;
        }

        // 数组双指针技巧，合并两个有序数组
        int i = lo, j = mi + 1;
        for (int p = lo; p <= hi; p++) {
            if (i == mi + 1) {
                presum[p] = temp[j++];
            } else if (j == hi + 1) {
                presum[p] = temp[i++];
            } else if (temp[i] > temp[j]) {
                presum[p] = temp[j++];
            } else {
                presum[p] = temp[i++];
            }
        }
    }
};
// @lc code=end

