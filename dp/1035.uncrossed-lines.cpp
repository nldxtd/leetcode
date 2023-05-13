/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> now(len1+1, 0);
        vector<int> next(len1+1, 0);
        int curline = 1;
        while (curline <= len2) {
            for (int i = 1; i <= len1; i++) {
                if (nums1[i-1] == nums2[curline-1]) next[i] = now[i-1]+1;
                else next[i] = max(next[i-1], now[i]);
            }
            curline++;
            now.swap(next);
        }
        return now[len1];
    }
};
// @lc code=end

