/*
 * @lc app=leetcode id=2405 lang=cpp
 *
 * [2405] Optimal Partition of String
 */

// @lc code=start

// 可以使用bitmap用来判断访问
class Solution {
public:
    int partitionString(string s) {
        int ans = 0, len = s.size();
        vector<bool> count(26, false);
        int index = 0;
        while (index < len) {
            if (count[s[index]-'a']) {
                ans += 1;
                for (int i = 0; i < 26; i++) {
                    count[i] = false;
                }
            } else {
                count[s[index]-'a'] = true;
                index++;
            }
        }
        return ans+1;
    }
};
// @lc code=end

