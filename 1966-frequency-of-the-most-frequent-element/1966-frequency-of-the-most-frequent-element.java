class Solution {
    public int maxFrequency(int[] nums, int k) {
        int maxFreq = 0;
        long currentSum = 0;

        Arrays.sort(nums);

        for (int left = 0, right = 0; right < nums.length; right++) {
            currentSum += nums[right];

            while (currentSum + k < (long)nums[right] * (right - left + 1)) {
                currentSum -= nums[left];
                left++;
            }

            maxFreq = Math.max(maxFreq, right - left + 1);
        }
        return maxFreq;
    }
}