class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // 左边乘积
        for(int i = 1 ; i < n ; i++){
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // 右边乘积
        int right = 1; // 定义变量right累积右边的乘积
        for(int i = n - 1 ; i >= 0 ; i--){
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};
















