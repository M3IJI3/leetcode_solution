class Solution {
    public double findMaxAverage(int[] nums, int k) {
        // double avg = Integer.MIN_VALUE;

        // int left = 0 ;
        // int right = k - 1;

        // while(right < nums.length)
        // {
        // int sum = 0;
        // for(int i = left ; i <= right ; i++)
        // {
        // sum += nums[i];
        // }
        // avg = Math.max(avg, (double) sum / k);
        // left++;
        // right++;
        // }

        // return avg;
        // --------------------------------------------

        double max = Integer.MIN_VALUE;

        int left = 0;
        int right = k - 1;
        int window = 0;

        for (int i = 0; i < k; i++) {
            window += nums[i];
        }

        while (right != nums.length) {
            max = Math.max(max, (double) window / k);

            right++;

            window -= nums[left];
            left++;

            if (right != nums.length) {
                window += nums[right];
            }

        }
        return max;
    }
}