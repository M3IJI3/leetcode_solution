class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0] + linearRob(nums, 2, n - 1), linearRob(nums, 1, n));
    }

    int linearRob(vector<int>& nums, int start, int end){
        int f0 = 0, f1 = 0;
        for(int i = start ; i < end ; i++){
            int new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};