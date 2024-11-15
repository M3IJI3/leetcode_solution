class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        // TLE
        // int k = 0;
        // while(k < nums.length)
        // {
        //     for(int i = 0 ; i < nums.length - k ; i++)
        //     {
        //         int sum = 0;
        //         for(int j = i ; j <= i + k ; j++)
        //         {
        //             sum += nums[j];
        //         }
        //         if(sum >= target) return k + 1;
        //     }
        //     k++;
        // }
        // return 0;
        // -----------------------------------------------
        
        int sum = 0;
        int minLength = Integer.MAX_VALUE;
        int left = 0;

        for(int right = 0 ; right < nums.length ; right++)
        {
            sum += nums[right];

            while(sum >= target)
            {
                minLength = Math.min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minLength == Integer.MAX_VALUE ? 0 : minLength;
    }
}