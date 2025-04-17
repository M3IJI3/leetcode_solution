// TLE
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         int count = 0;
//         backtrack(nums, target, count);
//         return count;
//     }
// private:
//     void backtrack(const vector<int>& nums, int target, int& count){
//         if(target == 0){
//             count++;
//             return;
//         }

//         for(int i = 0 ; i < nums.size() ; i++){
//             // 在每层递归时未更新target的值
//             // if(target > 0){
//             //     target -= nums[i];
//             //     backtrack(nums, target, count);
//             // }
//             if(target >= nums[i]){
//                 backtrack(nums, target - nums[i], count);
//             }
//         }
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i] = 表示组成数字 i 的排列个数
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};
