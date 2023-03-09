/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0, valid = 0;
        unordered_map<char, int> count, need;
        for (char c : s1) {
            need[c]++;
        }
        while(right < s2.size()) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                count[c]++;
                if (need[c] == count[c]) valid++;
            }
            while(right-left >= s1.size()) {
                if (valid == need.size()) return true;
                char d = s2[left];
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (count[d] == need[d])
                        valid--;
                    count[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

