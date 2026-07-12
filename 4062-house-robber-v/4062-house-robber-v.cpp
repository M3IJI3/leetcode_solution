class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        long long notRob = 0;
        long long rob = nums[0];

        for(int i = 1 ; i < n ; i++){
            // 当前不偷
            long long newNotRob = max(notRob, rob);

            // 当前偷
            long long newRob;
            if(colors[i] == colors[i - 1]){
                newRob = notRob + nums[i]; 
            } else {
                newRob = max(notRob, rob) + nums[i];
            }

            notRob = newNotRob;
            rob = newRob;
        }
        return max(notRob, rob);
    }
};