/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> count(n, 1);
        vector<int> c(n, 0);
        std::iota(c.begin(), c.end(), 1);
        for (int i = 1; i < n; i++) count[i] = count[i-1]*i;
        while (n>0) {
            int index = (k%count[n-1]==0)?k/count[n-1]-1 : k/count[n-1];
            ans += c[index]+'0';
            c.erase(c.begin()+index);
            k = (k%count[n-1]==0) ? count[n-1] : k%count[n-1];
            n--;
        }
        return ans;
    }
};
// @lc code=end

