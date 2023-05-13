/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */

// @lc code=start
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> count(high+1, 0);
        count[0] = 1;
        for (int i = 0; i < high; i++) {
            if (i+zero <= high) count[i+zero] = add(count[i+zero], count[i]); 
            if (i+one <= high) count[i+one] = add(count[i+one], count[i]);
        }
        int ans = 0;
        for (int i = low; i <= high; i++) 
            ans = add(ans, count[i]);
        return ans;
    }

    int add(int a, int b) {
        int sum = a+b;
        return sum >= 1e9+7 ? sum-1e9-7 : sum;
    }
};
// @lc code=end
