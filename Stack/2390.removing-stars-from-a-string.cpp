/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
class Solution {
public:
    string removeStars(string s) {
        int i=0,j=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='*'){
                j--;
            }else{
                s[j++] = s[i];
            }
        }
        return s.substr(0,j);
    }
};
// @lc code=end

