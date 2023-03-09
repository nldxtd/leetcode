/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, res = 0;
        unordered_map<char, int> count;
        while(right < s.size()) {
            char c = s[right];
            right++;
            count[c]++;
            while(count[c] > 1) {
                char d = s[left];
                left++;
                count[d]--;
            }
            res = max(res, right-left);
        }
        return res;
    }
};
// @lc code=end

