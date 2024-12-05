class Solution {
    public int longestSubarray(int[] nums) {
        // int left = 0;
        // int zeros = 0;
        // int maxLen = 0;

        // for(int right = 0 ; right < nums.length ; right++)
        // {
        //     if(nums[right] == 0)
        //     {
        //         zeros++;
        //     }

        //     while(zeros > 1)
        //     {
        //         zeros--;
        //         left++;
        //     }
        //     maxLen = Math.max(maxLen, right - left);
        // } 

        // return maxLen;       

        // --------------------------------------------

        int left = 0 ;
        int zeros = 0;
        int maxLen = 0;

        for(int right = 0 ; right < nums.length ; right++)
        {
            if(nums[right] == 0)
            {
                zeros++;
            }

            while(zeros > 1)
            {
                if(nums[left] == 0)
                {
                    zeros--;
                }
                left++;
            }
            
            maxLen = Math.max(maxLen, right - left + 1 - zeros);
        }
        return maxLen == nums.length ? maxLen - 1 : maxLen;
    }
}