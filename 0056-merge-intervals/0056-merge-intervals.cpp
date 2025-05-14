class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) return result;

        sort(intervals.begin(), intervals.end());

        vector<int> current = intervals[0];
        for(int i = 1 ; i < intervals.size() ; i++){
            // 有overlap
            if(current[1] >= intervals[i][0]){
                current[1] = max(current[1], intervals[i][1]);
            // 无overlap
            } else {
                result.push_back(current);
                current = intervals[i];
            }
        }

        result.push_back(current);
        return result;
    }
};