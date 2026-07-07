class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n + 1);
        for(int i = 0 ; i < n ; i++){
            presum[i + 1] = presum[i] + nums[i];
        }

        // 找右边的最大值 - 左边的最小值
        int minPresum = presum[0];
        int maxSum = INT_MIN;
        for(int i = 1 ; i < presum.size() ; i++){
            int currSum = presum[i] - minPresum;
            maxSum = max(maxSum, currSum);
            minPresum = min(minPresum, presum[i]);
        }
        return maxSum;
    }
};

// 0 -2 -1 -4 0 -1 1 2 -3 1 