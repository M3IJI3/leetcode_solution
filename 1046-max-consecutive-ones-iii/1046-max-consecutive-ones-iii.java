class Solution {
    public int longestOnes(int[] nums, int k) {
        // Map<Integer, Integer> map = new HashMap<>();
        // int maxLen = 0;

        // for(int i = 0 ; i < nums.length ; i++)
        // {
        //     for(int j = i ; j < nums.length ; j++)
        //     {
        //         map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
                
        //         if(map.containsKey(0) && map.get(0) == k)
        //         {
        //             maxLen = Math.max(maxLen, j - i + 1);
        //             System.out.println(i + ", " + j);
        //             break;
        //         }
        //     }
        //     map.clear();
        // }
        // return maxLen;

        // --------------------------------------------------

        int start = 0;
        int end  = 0;
        int zeros = 0;

        while(end < nums.length)
        {
            if(nums[end] == 0)
            {
                zeros++;
            }
            end++;

            if(zeros > k)
            {
                if(nums[start] == 0)
                {
                    zeros--;
                }
                start++;
            }
        }
        return end - start;
    }
}