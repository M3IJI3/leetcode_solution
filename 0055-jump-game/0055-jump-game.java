class Solution {
    public boolean canJump(int[] nums) {
        int dest = nums.length - 1;

        for(int i = nums.length - 1 ; i > 0 ; i--)
        {
            if(nums[i - 1] + (i - 1) >= dest)
            {
                dest = i - 1;
            }
        }

        return dest == 0;
    }
}