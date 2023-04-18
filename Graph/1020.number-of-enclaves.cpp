/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
    int ans;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        ans = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    int count = 0;
                    if (!dfs(grid, i, j, count)) ans += count;
                }
            }
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& g, int i, int j, int& count){
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()){
            return true;
        }
        if (g[i][j] == 0){
            return false;
        }
        count += 1;
        g[i][j] = 0;
        /* IMPORTANT NOTE: 
        WHY I CANNOT USE `return dfs(g, i+1, j) && dfs(g, i, j+1) && dfs(g, i-1, j) && dfs(g, i, j-1);`???
        BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T
        HAVE THE CHANCE TO MARK THOSE 0s TO 1s!!!
        */
        bool d1 = dfs(g, i+1, j, count);
        bool d2 = dfs(g, i, j+1, count);
        bool d3 = dfs(g, i-1, j, count);
        bool d4 = dfs(g, i, j-1, count);
        return (d1 || d2 || d3 || d4);
    }
};
// @lc code=end

