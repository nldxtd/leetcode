/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
public:
    double average(vector<int>& s) {
        return (accumulate(begin(s), end(s), 0.) - *min_element(begin(s), end(s)) 
            - *max_element(begin(s), end(s))) / (s.size() - 2);
    }
};
// @lc code=end

