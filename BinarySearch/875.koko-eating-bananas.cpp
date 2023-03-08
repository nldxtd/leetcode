/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minv = 0, maxv = 0;
        for (int pile : piles) {
            if (pile > maxv) maxv = pile;
        }
        return calMinV(piles, minv, maxv, h);
    }

    int calMinV(vector<int>& piles, int minv, int maxv, int h) {
        int midv = (minv+maxv) / 2;
        if (midv == minv) return maxv;
        long long time = 0;
        for (int pile : piles) {
            time += ceil(pile * 1.0 / midv);
        }
        if (time <= h) return calMinV(piles, minv, midv, h);
        else return calMinV(piles, midv, maxv, h);
    }
};
// @lc code=end

