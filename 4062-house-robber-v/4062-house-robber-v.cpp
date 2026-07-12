class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = 0; dp[0][1] = nums[0];

        for(int i = 1 ; i < n ; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

            if(colors[i] == colors[i - 1]){
                dp[i][1] = dp[i - 1][0] + nums[i];
            } else {
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + nums[i];
            }
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};