class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(maxSum(nums, firstLen, secondLen), maxSum(nums, secondLen, firstLen));
    }
private:
    int maxSum(vector<int>& nums, int L, int M){
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // 计算并存储前缀和
        for(int i = 0 ; i < n ; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int maxL = 0;
        int result = 0;

        for(int i = L + M ; i <= n ; i++){
            maxL = max(maxL, prefix[i - M] - prefix[i - M - L]);
            result = max(result, maxL + prefix[i] - prefix[i - M]);
        }

        return result;
    }
};