class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = nums[0];

        for(int i = 2 ; i <= n ; i++){
            // dp[i - 1]: 不偷第 i 间
            // dp[i - 2] + nums[i - 1]: 偷第 i 间
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};