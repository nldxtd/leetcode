/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
    vector<int> presum;
public:
    Solution(vector<int>& w) {
        int sum = 0;
        presum.push_back(sum);
        for (int _w : w) {
            sum += _w;
            presum.push_back(sum);
        }
    }
    
    int pickIndex() {
        int target = rand() % presum[presum.size()-1] + 1;
        return right_bound(target);
    }

    int right_bound(int target) {
        int left = 0, right = presum.size()-1;
        while (left < right-1) {
            int mid = (left+right) / 2;
            if (presum[mid] < target) {
                left = mid;
            } else if (presum[mid] > target) {
                right = mid;
            } else {
                return mid-1;
            }
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

