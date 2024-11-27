class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int count = 0; // 记录优美子数组的数量
        int oddCount = 0; // 窗口内奇数的数量
        int left = 0;
        int result = 0;

        for (int right = 0; right < nums.length; right++) {
            if (nums[right] % 2 == 1) {
                oddCount++;
                count = 0;
            }

            while (oddCount == k) {
                if (nums[left] % 2 == 1) {
                    oddCount--;
                }
                left++;
                count++;
            }

            result += count;
        }
        return result;

    }
}