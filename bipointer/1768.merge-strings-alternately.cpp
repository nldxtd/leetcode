/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */
// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int len1 = word1.size();
        int len2 = word2.size();
        int len = len1 < len2 ? len1 : len2;
        s.resize(len1+len2);
        int i=0,j=0, index = 0;
        while (i < len) {
            s[index++] = word1[i++];
            s[index++] = word2[j++];
        }
        while (i < len1) {
            s[index++] = word1[i++];
        }
        while (j < len2) {
            s[index++] = word1[j++];
        }
        return s;
    }
};
// @lc code=end

