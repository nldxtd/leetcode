/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
public:
    int min;
    set<int> st;
    SmallestInfiniteSet() {
        min = 1;
    }
    
    int popSmallest() {
        if (st.size() > 0) {
            int t = *st.begin();
            st.erase(st.begin());
            return t;
        } 
        return min++;
    }
    
    void addBack(int num) {
        if (num < min) 
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

