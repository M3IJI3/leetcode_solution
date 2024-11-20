class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int current = 0;
        int result = 0;

        for (int i = 2; i < nums.length; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                current++;
                result += current;
            } else {
                current = 0;
            }
        }
        return result;
    }
}