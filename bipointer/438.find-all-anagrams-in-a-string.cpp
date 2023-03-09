/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0, valid = 0;
        vector<int> ans;
        unordered_map<char, int> count, need;
        for (char c : p) {
            need[c]++;
        }
        while(right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                count[c]++;
                if (need[c] == count[c]) valid++;
            }
            while(right-left >= p.size()) {
                if (valid == need.size())
                ans.push_back(left);
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (count[d] == need[d])
                        valid--;
                    count[d]--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

