/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory {
    vector<string> history;
    int index;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        index = 0;
    }
    
    void visit(string url) {
        history.erase(history.begin()+index+1, history.end());
        history.push_back(url);
        index = history.size()-1;
    }
    
    string back(int steps) {
        if (steps > index) steps = index;
        index -= steps;
        return history[index];
    }
    
    string forward(int steps) {
        if (index + steps > history.size()-1) steps = history.size()-1-index;
        index += steps;
        return history[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

