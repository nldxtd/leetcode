/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int j=0;
        int res=1;
        for(int i=1;i<pairs.size();i++) {
            if(pairs[i][0]>pairs[j][1]) {
                j=i;
                res++;
            }
        }
        return res;
    }
    static bool cmp(vector<int>& a,vector<int>& b) {
        return a[1]<b[1];
    }
};
// @lc code=end

