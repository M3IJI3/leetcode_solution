class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // 因为按照start排序
        // 所以只需要比较右边界
        // 如果start相同 右边界大的放左边
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 0;
        int maxEnd = 0;

        for(const auto& interval : intervals){
            if(interval[1] <= maxEnd){
                count++;
            } else {
                maxEnd = interval[1];
            }
        }

        return intervals.size() - count;
    }
};