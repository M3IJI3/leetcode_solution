class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max   = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
                count += 1;
            } 

            if(nums[i] != 1 || i == nums.size() - 1){
                max = count > max ? count : max;
                count = 0;
            }
        }
        return max;
    }
};