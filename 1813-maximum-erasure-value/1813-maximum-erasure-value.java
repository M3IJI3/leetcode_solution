class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        // int left = 0;
        // int score = 0;
        // int max = 0;

        // HashMap<Integer, Integer> window = new HashMap<>();

        // for(int right = 0 ; right < nums.length ; right++)
        // {
        // int rightNum = nums[right];
        // window.put(rightNum, window.getOrDefault(rightNum, 0) + 1);
        // score += rightNum;

        // while(window.get(rightNum) > 1)
        // {
        // int leftNum = nums[left];
        // window.put(leftNum , window.get(leftNum) - 1);
        // score -= leftNum;
        // left++;
        // }
        // max = Math.max(max, score);
        // }

        // return max;
        // -------------------------------------------------------------

        // Set<Integer> set = new HashSet<>();
        // int maxSum = 0;
        // int currSum = 0;

        // for (int l = 0, r = 0; r < nums.length; r++) {
        //     currSum += nums[r];
        //     if (set.contains(nums[r])) {
        //         while (nums[l] != nums[r]) {
        //             currSum -= nums[l];
        //             set.remove(nums[l]);
        //             l++;
        //         }
        //         if (nums[l] == nums[r]) {
        //             currSum -= nums[l];
        //             set.remove(nums[l]);
        //             l++;
        //         }
        //     }
        //     set.add(nums[r]);
        //     maxSum = Math.max(currSum, maxSum);

        // }
        // return maxSum;

        // --------------------------------------------------------------

        int start = 0;
        int end = 0;
        int sum = 0;
        int max = 0;
        boolean[] freq = new boolean[10001];

        while (end < nums.length) {
            while (freq[nums[end]]) {
                sum -= nums[start];
                freq[nums[start]] = false;
                start++;
            }
            freq[nums[end]] = true;
            sum += nums[end];
            max = Math.max(max, sum);
            end++;
        }
        
        return max;
    }
}