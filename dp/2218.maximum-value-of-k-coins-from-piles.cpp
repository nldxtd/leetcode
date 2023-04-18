/*
 * @lc app=leetcode id=2218 lang=cpp
 *
 * [2218] Maximum Value of K Coins From Piles
 */

// @lc code=start
class Solution {
    vector<vector<int>> presum;
    vector<vector<int>> dp;
    int pile_num;
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        pile_num = piles.size();
        presum.resize(pile_num);
        dp.resize(pile_num, vector<int>(k+1, -1));
        for (int i = 0; i < pile_num; i++) {
            int sum = 0;
            presum[i].push_back(sum);
            for (int j = 0; j < piles[i].size(); j++) {
                sum += piles[i][j];
                presum[i].push_back(sum);
            }
        }
        return find_maxsum(piles, 0, k);
    }

    int find_maxsum(vector<vector<int>>& piles, int cur, int k) {
        if (k == 0) return 0;
        if (cur == pile_num-1) {
            int index = piles[cur].size() < k ? piles[cur].size() : k;
            return presum[cur][index];
        }
        if (dp[cur][k] > -1) return dp[cur][k];
        
        int max_sum = 0;
        for (int i = 0; i <= piles[cur].size() && i <= k; i++) {
            int temp_sum = presum[cur][i] + find_maxsum(piles, cur+1, k-i);
            if (temp_sum > max_sum) max_sum = temp_sum;
        }
        dp[cur][k] = max_sum;
        return dp[cur][k];
    }
};
// @lc code=end

