class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int presum = 0, maxAns = nums[0];
        for(int x : nums){
            presum = max(presum + x, x);
            maxAns = max(maxAns, presum);
        }
        return maxAns;
    }
};