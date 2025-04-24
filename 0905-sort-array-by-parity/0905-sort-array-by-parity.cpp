class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right){
            // 如果左指针是奇数
            if(nums[left] % 2 != 0){
                if(nums[right] % 2 == 0){
                    int temp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = temp;
                } else {
                    right--;
                }
            } else {
                left++;
            }
        }
        return nums;
    }
};