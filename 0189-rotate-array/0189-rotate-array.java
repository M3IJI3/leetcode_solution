class Solution {
    public void rotate(int[] nums, int k) {
        // TIME LIMIT EXCEED -> O(n^2)
        // k = k % nums.length;
        // while(k > 0)
        // {
        //     for(int i = 0 ; i < nums.length - 1 ; i++)
        //     {
        //         int temp = nums[nums.length - i - 1];
        //         nums[nums.length - i - 1] = nums[nums.length - i - 2];
        //         nums[nums.length - i - 2] = temp;
        //     }
        //     k--;
        // }

        int n = nums.length;
        k = k % n; // remainder, 即数组向又移动的次数
        int[] rotated = new int[n];

        for(int i = 0 ; i < n ; i++)
        {
            rotated[(i + k) % n] = nums[i];
        }

        for(int i = 0; i < n ; i++)
        {
            nums[i] = rotated[i];
        }
    }
}