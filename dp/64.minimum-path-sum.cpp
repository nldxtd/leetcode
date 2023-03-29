/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int map_sum[n][m];
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += grid[0][j];
            map_sum[0][j] = sum;
        }
        sum = grid[0][0];
        for (int i = 1; i < n; i++) {
            sum += grid[i][0];
            map_sum[i][0] = sum;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                map_sum[i][j] = min(map_sum[i-1][j], map_sum[i][j-1]) + grid[i][j];
            }
        }
        return map_sum[n-1][m-1];
    }
};
// @lc code=end

