class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // 1. 统计每个数字的价值
        unordered_map<int, int> count;
        int maxNum = 0;
        for(int num: nums){
            count[num] += num;
            maxNum = max(maxNum, num);
        }

        // 2. 构建价值数组
        vector<int> sum(maxNum + 1, 0);
        for(int i = 1 ; i <= maxNum ; i++){
            if(count.count(i)){
                sum[i] = count[i];
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