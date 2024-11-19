class Solution {
    public int findLHS(int[] nums) {
        // if (nums.length == 1)
        //     return 0;

        // Map<Integer, Integer> map = new HashMap<>();

        // for (int n : nums) {
        //     map.put(n, map.getOrDefault(n, 0) + 1);
        // }

        // int maxLen = 0;
        // for (int i = 0; i < nums.length - 1; i++) {
        //     if (map.containsKey(nums[i] - 1)) {
        //         maxLen = Math.max(maxLen, map.get(nums[i]) + map.get(nums[i] - 1));
        //     }

        //     if (map.containsKey(nums[i] + 1)) {
        //         maxLen = Math.max(maxLen, map.get(nums[i]) + map.get(nums[i] + 1));
        //     }
        // }

        // return maxLen;

        // -----------------------------------------------

        if(nums.length == 1) return 0;

        Map<Integer, Integer> map = new HashMap<>();

        for(int n : nums)
        {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }

        int maxLen = 0;
        for(int key: map.keySet())
        {
            if(map.containsKey(key) && map.containsKey(key + 1))
            {
                maxLen = Math.max(maxLen, map.get(key) + map.get(key + 1));
            }
        }
        return maxLen;
    }
}