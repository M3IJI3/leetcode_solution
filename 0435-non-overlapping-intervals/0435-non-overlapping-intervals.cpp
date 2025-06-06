class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 0;
        int lastInterval = intervals[0][1];
        for(int i = 1 ; i < intervals.size() ; i++){
            if(intervals[i][0] < lastInterval){
                count++;
            } else {
                lastInterval = intervals[i][1];
            }
        }
        return count;
    }
};