class Solution {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int left = findEven(nums, threshold, 0);
        if(left == nums.length) return 0;

        int right = left + 1;
        int maxLen = 1;
        int i = 1;
        while(right < nums.length)
        {
            if(nums[right] <= threshold && nums[right] % 2 == i++)
            {
                i %= 2;
            }
            else
            {
                maxLen = Math.max(maxLen, right - left);
                left = findEven(nums, threshold, right);
                right = left;
                i = 1;
            }
            right++;
        }
        maxLen = Math.max(maxLen, right - left);
        return maxLen;
    }

    public static int findEven(int[] nums, int threshold, int i)
    {
        while(i < nums.length)
        {
            if(nums[i] <= threshold && nums[i] % 2 == 0 ) break;
            i++;
        }
        return i;
    }
}