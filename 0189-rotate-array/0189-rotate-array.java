class Solution {
    public void rotate(int[] nums, int k) {
        // k = k % nums.length;

        // if(k != 0)
        // {
        //     int[] array = new int[nums.length];
        //     System.arraycopy(nums, nums.length - k, array, 0, k);
        //     System.arraycopy(nums, 0, array, k, nums.length - k);
        //     System.arraycopy(array, 0, nums, 0, nums.length);
        // }

        int n = nums.length;
        k = k % n;

        reverse(nums, 0, n - 1); // 先反转整个数组
        reverse(nums, 0, k - 1); // 再反转  (0, k-1)
        reverse(nums, k, n - 1); // 最后反转(k, n-1)

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