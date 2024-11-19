class Solution {
    public int lengthOfLongestSubstring(String s) {
        // int left = 0;
        // int maxLen = 0;
        // HashSet<Character> set = new HashSet<>(); // hashset 具有数值的唯一性

        // for (int right = 0; right < s.length(); right++) {
        //     while (set.contains(s.charAt(right))) {
        //         set.remove(s.charAt(left));
        //         left++;
        //     }
        //     set.add(s.charAt(right));
        //     maxLen = Math.max(maxLen, right - left + 1);
        // }
        // return maxLen;

        // ----------------------------------------------------

        int left = 0;
        int maxLen = 0;
        Map<Character, Integer> map = new HashMap<>();

        for(int right = 0 ; right < s.length() ; right++)
        {
            char c = s.charAt(right);
            map.put(c, map.getOrDefault(c, 0) + 1);

            while(map.get(c) > 1)
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