/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int len = days.size();
        vector<int> ans(len, 0);
        int cost1 = 0, cost2 = 0, cost3 = 0;
        ans[0] = min(costs[0], min(costs[1], costs[2]));
        for (int i = 1; i < len; i++) {
            cost1 = ans[i-1] + costs[0];
            cost2 = (days[i] <= days[0]+6) ? costs[1] : ans[prev(lower_bound(days.begin(), days.end(), days[i]-6))-days.begin()] + costs[1];
            cost3 = (days[i] <= days[0]+29) ? costs[2] : ans[prev(lower_bound(days.begin(), days.end(), days[i]-29))-days.begin()] + costs[2];
            ans[i] = min(cost1, min(cost2, cost3));
        }
        return ans[len-1];
    }
};
// @lc code=end

