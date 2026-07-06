class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 0, maxEnd = 0;
        for(auto& interval : intervals){
            if(interval[1] <= maxEnd){
                count++;
            } else {
                maxEnd = interval[1];
            }
        }
        return intervals.size() - count;
    }
};