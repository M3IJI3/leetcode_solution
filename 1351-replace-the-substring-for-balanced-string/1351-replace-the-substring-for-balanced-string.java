class Solution {
    public int balancedString(String s) {
        // Map<Character, Integer> map = new HashMap<>();
        // for(char c: s.toCharArray())
        // {
        //     map.put(c, map.getOrDefault(c, 0) + 1);
        // }

        // int minLen = 0;
        // for(char c: map.keySet())
        // {
        //     if(map.get(c) > s.length() / 4)
        //     {
        //         minLen += map.get(c) - s.length() / 4;
        //     }
        // }
        // return minLen;
        // ----------------------------------------------

        int n = s.length();
        int target = n / 4;
        Map<Character, Integer> count = new HashMap<>();

        for(char c: s.toCharArray())
        {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }

        // 检查是否已经平衡
        if(isBalanced(count, target))
        {
            return 0;
        }

        int left = 0, minLength = n;
        
        // 滑动窗口
        for(int right = 0 ; right < n ; right++)
        {
            char rightChar = s.charAt(right);
            count.put(rightChar, count.get(rightChar) - 1);

            while(isBalanced(count, target))
            {
                minLength = Math.min(minLength, right - left + 1);
                char leftChar = s.charAt(left);
                count.put(leftChar, count.get(leftChar) + 1);
                left++;
            }
        }
        return minLength;
    }

    private boolean isBalanced(Map<Character, Integer> count, int target)
    {
        return count.getOrDefault('Q', 0) <= target &&
               count.getOrDefault('W', 0) <= target &&
               count.getOrDefault('E', 0) <= target &&
               count.getOrDefault('R', 0) <= target;
    }
}