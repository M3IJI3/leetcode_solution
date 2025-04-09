class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            // if(i % 2 == 0){
            //     sum += nums[i];
            // }
            sum += i % 2 == 0 ? nums[i] : 0;
        }
        return sum;
    }
};