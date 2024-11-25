class Solution {
    public int longestOnes(int[] nums, int k) {
        // int start = 0;
        // int end = 0;
        // int zeros = 0;

        // while(end < nums.length)
        // {
        // if(nums[end] == 0)
        // {
        // zeros++;
        // }
        // end++;

        // if(zeros > k)
        // {
        // if(nums[start] == 0)
        // {
        // zeros--;
        // }
        // start++;
        // }
        // }
        // return end - start;

        // -----------------------------------------------------

        int start = 0;
        int end = 0;
        int zeros = 0;
        int maxLength = 0;

        while (end < nums.length) {
            // 右边界扩展
            if (nums[end] == 0) {
                zeros++;
            }
            end++;

            // 当零的数量超过 k 时，收缩窗口
            while (zeros > k) {
                if (nums[start] == 0) {
                    zeros--;
                }
                start++;
            }

            // 计算当前窗口的大小
            maxLength = Math.max(maxLength, end - start);
        }

        return maxLength;
    }
}