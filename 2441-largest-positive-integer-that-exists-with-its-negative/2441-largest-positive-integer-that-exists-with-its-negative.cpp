class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0;
        while(nums[left] < 0 && nums[nums.size() - 1] > 0){
            int right = nums.size() - 1;
            while(nums[right] > 0){
                if(abs(nums[left]) == nums[right]){
                    return nums[right];
                }
                right--;
            }
            left++;
        }
        return -1;
    }
};