class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        // 留下异端连续子数组让他的和最小
        // 总共n张牌, 取走其中的k张, 等价于使剩下的 n - k 张连续子数组的和最小

        // 计算所有牌的和
        // int total = 0;
        // for(int num : nums) total += num;

        // int right = nums.size() - k - 1, left = 0;
        // int minSum = INT_MAX;
        // int sum = 0;
        
        // while(right < nums.size()){
        //     for(int i = left ; i <= right ; i++){
        //         sum += nums[i];
        //     }

        //     minSum = min(minSum, sum);
        //     left++;
        //     right++;
        //     sum = 0;
        // }

        // return total - minSum;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        int n = nums.size();
        int total = 0;

        for(int num: nums) total += num;
        if(k == n) return total;

        int widow = n - k;

        int sum = 0;
        for(int i = 0 ; i < widow ; i++){
            sum += nums[i];
        }

        int minSum = sum;

        for(int i = widow ; i < n ; i++){
            sum += nums[i];
            sum -= nums[i - widow];
            minSum = min(minSum, sum);
        }

        return total - minSum;
    }
};