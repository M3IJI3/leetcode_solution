class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        long long notRobCurrent = 0;
        long long robCurrent = nums[0];

        for(int i = 1 ; i < n ; i++){
            long long newNotRob = max(notRobCurrent, robCurrent);

            long long newRob;
            if(colors[i] == colors[i - 1]){
                newRob = notRobCurrent + nums[i];
            } else {
                newRob = max(notRobCurrent, robCurrent) + nums[i];
            }

            notRobCurrent = newNotRob;
            robCurrent = newRob;
        }
        return max(notRobCurrent, robCurrent);
    }
};