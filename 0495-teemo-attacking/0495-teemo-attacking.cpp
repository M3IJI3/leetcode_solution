class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // TLE
        // unordered_set<int> set;

        // for(int i = 0 ; i < timeSeries.size() ; i++){
        //     for(int j = 0 ; j < duration ; j++){
        //         set.insert(timeSeries[i] + j);
        //     }
        // }

        // return set.size();
        ////////////////////////////////////////////////

        int total = 0;

        for(int i = 0 ; i < timeSeries.size() - 1 ; i++){
            int diff = timeSeries[i + 1] - timeSeries[i];
            total += min(diff, duration);
        }
        
        if(!timeSeries.empty()) total += duration;
        return total;
    }
};