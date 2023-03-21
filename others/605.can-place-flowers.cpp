/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
    int size;
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        size = flowerbed.size();
        for (int i = 0; i < size; i++) {
            if (canPlant(flowerbed, i)) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }

    bool canPlant(vector<int>& f, int i) {
        return (f[i] == 0) &&
            ((i == 0) || (f[i-1] == 0)) &&
            ((i == size-1) || (f[i+1] == 0));
    }
};
// @lc code=end

