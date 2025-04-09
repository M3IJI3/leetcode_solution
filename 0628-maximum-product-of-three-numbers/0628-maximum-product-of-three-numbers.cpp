class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());

        int max_product = 0;

        // all positive or negative numbers after sorting,
        // maximum product: by multiplying the three numbers to the right
        // if(nums[0] * nums[size - 1] >= 0){
        //     max_product = nums[size - 1] * nums[size - 2] * nums[size - 3];
        // } else {
        //     // if there are both positive and negative numbers in array
        //     max_product = max(nums[0] * nums[1] * nums[size - 1], nums[size - 1] * nums[size - 2] * nums[size - 3]);
        // }
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        return max_product = max(
            nums[0] * nums[1] * nums[size - 1], 
            nums[size - 1] * nums[size - 2] * nums[size - 3]);
    }
};