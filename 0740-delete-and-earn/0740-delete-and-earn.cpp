class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int maxNum = 0;
        for(int num : nums){
            cnt[num] += num;
            maxNum = max(maxNum, num);
        }

        vector<int> sum(maxNum + 1, 0);
        for(int i = 1 ; i <= maxNum ; i++){
            if(cnt.count(i)){
                sum[i] = cnt[i];
            }
        }

        vector<int> dp(maxNum + 1, 0);
        dp[1] = sum[1];
        for(int i = 2 ; i <= maxNum ; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
        }
        return dp[maxNum];
    }
};