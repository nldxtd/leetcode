/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */

// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int maxSatisfaction(vector<int>& satisfaction) {
        int len = satisfaction.size();
        std::sort(satisfaction.begin(), satisfaction.end(), [](int a, int b) { return a > b; });
        vector<int> presum(len, 0);
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += satisfaction[i];
            presum[i] = sum;
        }
        int ans = 0;
        for (int i = 0; i < len && presum[i] >= 0; i++) {
            ans += presum[i];
        }
        return ans;
    }
    }
};
// @lc code=end

