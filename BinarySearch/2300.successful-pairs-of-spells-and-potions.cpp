/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        long long need;
        vector<int> ans;
        for(int spell:spells){
            need = ceil(success*1.0/spell);
            ans.push_back(potions.end()-lower_bound(potions.begin(),potions.end(),need));
        }
        return ans;
    }
};
// @lc code=end

