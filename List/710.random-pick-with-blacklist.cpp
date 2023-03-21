/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 */

// @lc code=start
class Solution {
public:
    int size;
    unordered_map<int, int> mapping;
    Solution(int n, vector<int>& blacklist) {
        size = n - blacklist.size();
        for (auto b : blacklist) {
            mapping[b] = 1;
        }
        int last = n-1;
        for (auto b : blacklist) {
            if (b >= size) continue;
            while (mapping.count(last)) last--;
            mapping[b] = last;
            last--;
        }
    }
    
    int pick() {
        int r = rand() % size;
        if (mapping.count(r)) return mapping[r];
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

