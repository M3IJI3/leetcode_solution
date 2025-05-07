class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        // TLE
        // unordered_set<int> set(special.begin(), special.end());

        // int floor = bottom;
        // int maxFloors = 0;
        // int currFloors = 0;
        // while(floor <= top){
        //     if(!set.count(floor)){
        //         currFloors++;
        //     } else {
        //         currFloors = 0;
        //     }
        //     maxFloors = max(maxFloors, currFloors);
        //     floor++;
        // } 
        // return maxFloors;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        sort(special.begin(), special.end());
        int n = special.size();
        int b2s = special[0] - bottom;
        int s2t = top - special[n - 1];
        int bigger = max(b2s, s2t);

        int maxFloors = 0;
        for(int i = 1 ; i < n ; i++){
            maxFloors = max(maxFloors, special[i] - special[i - 1] - 1);
        }

        return max(maxFloors, bigger);
    }
};