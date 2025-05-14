class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        for(const auto& interval : intervals){
            // 左边完全无重叠
            if(interval[1] < newInterval[0]){
                result.push_back(interval);
            // 右边完全无重叠
            } else if(interval[0] > newInterval[1]) {
                result.push_back(newInterval);
                newInterval = interval;
            // 有重叠
            } else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        result.push_back(newInterval);
        return result;
    }
};