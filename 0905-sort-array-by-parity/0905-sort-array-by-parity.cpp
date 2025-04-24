class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right){
            // 如果左指针是奇数, 准备被替换
            if(nums[left] % 2 != 0){
                // 并且右指针是偶数
                if(nums[right] % 2 == 0){
                    int temp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = temp;
                    
                    left++;
                    right--;
                    continue;
                }
                right--;
            } 
            left++;
        }
        return nums;
    }
};