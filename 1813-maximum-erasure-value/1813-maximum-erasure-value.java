class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int left = 0;
        int score = 0;
        int max = 0;

        HashMap<Integer, Integer> window = new HashMap<>();

        for(int right = 0 ; right < nums.length ; right++)
        {
            int rightNum = nums[right];
            window.put(rightNum, window.getOrDefault(rightNum, 0) + 1);
            score += rightNum;

            while(window.get(rightNum) > 1)
            {
                int leftNum = nums[left];
                window.put(leftNum , window.get(leftNum) - 1);
                score -= leftNum;
                left++;
            }

            max = Math.max(max, score);
        }

        return max;
    }
}