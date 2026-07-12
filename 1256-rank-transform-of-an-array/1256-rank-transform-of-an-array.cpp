class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // 排序去重
        vector<int> sorted_arr = arr;
        ranges::sort(sorted_arr);
        sorted_arr.erase(ranges::unique(sorted_arr).begin(), sorted_arr.end());

        for (int& x : arr) {
            // 二分得到编号
            x = ranges::lower_bound(sorted_arr, x) - sorted_arr.begin() + 1;
        }
        return arr;
    }
};