class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int sum = 0;
        int ans = 0;

        for(int i = 0 ; i < nums.length ; i++)
        {
            for(int j = i ; j < nums.length ; j++)
            {
                sum += nums[j];
                if(sum == goal)
                {
                    ans++;
                }
            }
            sum = 0;
        }

        return ans;
    }
}