/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
public:
    struct Pair {
        int val, id;
        Pair(int val, int id) {
            // 记录数组的元素值
            this->val = val;
            // 记录元素在数组中的原始索引
            this->id = id;
        }
    };
    
    // 归并排序所用的辅助数组
    Pair* temp;
    // 记录每个元素后面比自己小的元素个数
    int* count;
    
    // 主函数
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count = new int[n]();
        temp = new Pair[n]();
        Pair* arr = new Pair[n];
        // 记录元素原始的索引位置，以便在 count 数组中更新结果
        for (int i = 0; i < n; i++)
            arr[i] = Pair(nums[i], i);
        
        // 执行归并排序，本题结果被记录在 count 数组中
        sort(arr, 0, n - 1);
        
        vector<int> res;
        for (int i = 0; i < n; i++) 
            res.push_back(count[i]);
        delete[] count;
        delete[] temp;
        return res;
    }
    
    // 归并排序
    void sort(Pair* arr, int lo, int hi) {
        if (lo == hi) return;
        int mid = lo + (hi - lo) / 2;
        sort(arr, lo, mid);
        sort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }
    
    // 合并两个有序数组
    void merge(Pair* arr, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++) {
            temp[i] = arr[i];
        }
        
        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++) {
            if (i == mid + 1) {
                arr[p] = temp[j++];
            } else if (j == hi + 1) {
                arr[p] = temp[i++];
                // 更新 count 数组
                count[arr[p].id] += j - mid - 1;
            } else if (temp[i].val > temp[j].val) {
                arr[p] = temp[j++];
            } else {
                arr[p] = temp[i++];
                // 更新 count 数组
                count[arr[p].id] += j - mid - 1;
            }
        }
    }
};
// @lc code=end

