class Solution {
    public int minOperations(int[] nums, int x) {
        // Arrays.sort(nums);

        // if(nums[0] > x) return -1;

        // int left = 0;
        // int minCnt = Integer.MAX_VALUE;
        // int curSum = 0;

        // for(int right = 0 ; right < nums.length ; right++)
        // {
        //     curSum += nums[right];

        //     while(curSum > x)
        //     {
        //         curSum -= nums[left];
        //         left++;
        //     }

        //     if(curSum == x)
        //     {
        //         minCnt = Math.min(minCnt, right - left + 1); 
        //     }
        // }
        // return minCnt == Integer.MAX_VALUE ? -1 : minCnt;

        // --------------------------------------------------

        int target = -x, n = nums.length;
        for(int num : nums) target += num;

        if(target == 0) return n;

        int maxLen = 0, curSum = 0, left = 0;

        for(int right = 0 ; right < n ; right++)
        {
            curSum += nums[right];
            while(curSum > target && left <= right)
            {
                curSum -= nums[left];
                left++;
            }
            if(curSum == target)
            {
                maxLen = Math.max(maxLen, right - left + 1);
            }
        }
        return maxLen != 0 ? n - maxLen : -1;
    }
}