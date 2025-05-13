class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 双指针夹逼 必须是升序数组
        int left = 0, right = nums.size() - 1;

        while(left < right){
            if(nums[left] + nums[right] > target) right--;
            else if(nums[left] + nums[right] < target) left++;
            else break;
        }
        return { left + 1, right + 1 };
    }
};