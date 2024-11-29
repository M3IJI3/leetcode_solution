class Solution {
    public int maximumLengthSubstring(String s) {
        // int left = 0;
        // int right = 0;

        // Map<Character, Integer> window = new HashMap<>();
        // int maxLen = 0;

        // while (right < s.length()) {
        //     char rightChar = s.charAt(right);
        //     window.put(rightChar, window.getOrDefault(rightChar, 0) + 1);

        //     while (window.get(rightChar) > 2)
        //     {
        //         maxLen = Math.max(maxLen, right - left);
        //         window.put(s.charAt(left), window.get(s.charAt(left)) - 1);
        //         left++;
        //     }
            
        //     right++;
        // }
        // return maxLen;

        // ------------------------------------------
        
        int maxLen = 0;
        int left = 0;

        Map<Character, Integer> map = new HashMap<>();
        for(int right = 0 ; right < s.length() ; right++)
        {
            char rightChar = s.charAt(right);
            map.put(rightChar, map.getOrDefault(rightChar, 0) + 1);

            while(map.get(rightChar) > 2)
            {
                char leftChar = s.charAt(left);
                map.put(leftChar, map.get(leftChar) - 1);
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}