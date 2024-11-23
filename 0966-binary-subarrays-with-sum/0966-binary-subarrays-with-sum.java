class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        // BRUTE FORCE : O(n^2)
        // RUNNING TIME: 1862ms
        // int sum = 0;
        // int ans = 0;

        // for(int i = 0 ; i < nums.length ; i++)
        // {
        // for(int j = i ; j < nums.length ; j++)
        // {
        // sum += nums[j];
        // if(sum == goal)
        // {
        // ans++;
        // }
        // }
        // sum = 0;
        // }

        // return ans;

        // ---------------------------------------------

        // SLIDING WINDOW
        return atMost(nums, goal) - atMost(nums, goal - 1);

    }

    private int atMost(int[] nums, int goal) {
        if (goal < 0)
            return 0; 
        int left = 0, sum = 0, count = 0;
        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }
}