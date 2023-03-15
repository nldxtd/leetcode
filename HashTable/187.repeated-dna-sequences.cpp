/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> dna_to_num;
        dna_to_num['A'] = 1;
        dna_to_num['C'] = 2;
        dna_to_num['G'] = 3;
        dna_to_num['T'] = 4;
        // 记录重复出现的哈希值
        unordered_set<int> seen;
        // 记录重复出现的字符串结果
        unordered_set<string> res;

        // 数字位数
        int L = 10;
        // 进制
        int R = 4;
        // 存储 R^(L - 1) 的结果
        int RL = pow(R, L - 1);
        // 维护滑动窗口中字符串的哈希值
        int windowHash = 0;

        // 滑动窗口代码框架，时间 O(N)
        int left = 0, right = 0;
        while (right < s.size()) {
            // 扩大窗口，移入字符，并维护窗口哈希值（在最低位添加数字）
            windowHash = R * windowHash + dna_to_num[s[right]];
            right++;

            // 当子串的长度达到要求
            if (right - left == L) {
                // 根据哈希值判断是否曾经出现过相同的子串
                if (seen.count(windowHash)) {
                    // 当前窗口中的子串是重复出现的
                    res.insert(s.substr(left, right - left));
                } else {
                    // 当前窗口中的子串之前没有出现过，记下来
                    seen.insert(windowHash);
                }
                // 缩小窗口，移出字符，并维护窗口哈希值（删除最高位数字）
                windowHash = windowHash - dna_to_num[s[left]] * RL;
                left++;
            }
        }
        // 转化成题目要求的 vector 类型
        return vector<string>(res.begin(), res.end());
    }
};
// @lc code=end

