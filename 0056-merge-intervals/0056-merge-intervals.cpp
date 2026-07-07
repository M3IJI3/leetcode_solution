class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        vector<vector<int>> ans;
        vector<int> current = intervals[0];
        for(int i = 1 ; i < intervals.size() ; i++){
            if(current[1] >= intervals[i][0]){
                current[1] = max(current[1], intervals[i][1]);
            } else {
                ans.push_back(current);
                current = intervals[i];
            }
        }
        ans.push_back(current);
        return ans;
    }
};

// [1, 3][2, 6][8, 10][15, 18]