class Solution {
    public void rotate(int[] nums, int k) {
        // k = k % nums.length;
        // int[] temp = new int[nums.length];

        // System.arraycopy(nums, nums.length - k, temp, 0, k);
        // System.arraycopy(nums, 0, temp, k, nums.length - k);
        // System.arraycopy(temp, 0, nums, 0, nums.length);

        k = k % nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.length - 1);
    }

    private void reverse(int[] nums, int left, int right)
    {
        while(left < right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            
            left++;
            right--;
        }
    }
}