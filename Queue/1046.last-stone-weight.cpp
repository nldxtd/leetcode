/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> q;
        int x, y;
        
        for(auto x:stones)
            q.push(x);
        
        while(q.size() != 1){
            y = q.top();
            q.pop();
            x = q.top();
            q.pop();

            q.push(y-x);
        }
        
        return q.top();
    }
};
// @lc code=end

