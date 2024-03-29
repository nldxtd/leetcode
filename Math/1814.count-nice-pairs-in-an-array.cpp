/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long count = 0;
        unordered_map<int, long> mp;
        for(auto& num : nums) mp[num - rev(num)]++;        // counting frequency of each n - rev(n)
        for(auto& pair : mp)  // with each value, we can form n*(n-1)/2 pairs
            count = (count + (pair.second * (pair.second - 1)) / 2) % 1000000007; 
        /* Infact, the above can be done in a single pass as well which I didn't realise at the first try -
        for(auto& num : nums) count = (count + mp[num - reverseNum(num)]++) % 1000000007;
        */
        return count;
    }
    int rev(int n){
        int revNum = 0;
        while(n) revNum = revNum * 10 + (n % 10), n /= 10;
        return revNum;
    }
};
// @lc code=end

