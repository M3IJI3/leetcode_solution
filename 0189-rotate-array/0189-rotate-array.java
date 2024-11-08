class Solution {
    public void rotate(int[] nums, int k) {
        // TIME LIMIT EXCEED -> O(n^2)
        // k = k % nums.length;
        // while(k > 0)
        // {
        // for(int i = 0 ; i < nums.length - 1 ; i++)
        // {
        // int temp = nums[nums.length - i - 1];
        // nums[nums.length - i - 1] = nums[nums.length - i - 2];
        // nums[nums.length - i - 2] = temp;
        // }
        // k--;
        // }
        // -----------------------------------------------
        // O(n) Space Complexity
        // int n = nums.length;
        // k = k % n; // remainder, 即数组向又移动的次数
        // int[] rotated = new int[n];

        // for(int i = 0 ; i < n ; i++)
        // {
        // rotated[(i + k) % n] = nums[i];
        // }

        // for(int i = 0; i < n ; i++)
        // {
        // nums[i] = rotated[i];
        // }
        // ------------------------------------------------
        // O(n) Space Complexity
        // k = k % nums.length;

        // if(k != 0)
        // {
        // int[] temp = new int[nums.length];
        // System.arraycopy(nums, nums.length - k, temp, 0, k);
        // System.arraycopy(nums, 0, temp, k, nums.length - k);
        // System.arraycopy(temp, 0, nums, 0, nums.length);
        // }
        // ------------------------------------------------
        // O(1) Space Complexity
        k = k % nums.length;

        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }

    private void reverse(int[] nums, int left, int right) {
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
}