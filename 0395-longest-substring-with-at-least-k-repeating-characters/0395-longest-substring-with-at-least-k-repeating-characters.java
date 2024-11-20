class Solution {
    public int longestSubstring(String s, int k) {
        // if (s == null || s.length() == 0) {
        // return 0;
        // }

        // Map<Character, Integer> freq = new HashMap<>();
        // for (char c : s.toCharArray()) {
        // freq.put(c, freq.getOrDefault(c, 0) + 1);
        // }

        // for (int i = 0; i < s.length(); i++) {
        // if (freq.get(s.charAt(i)) < k) {
        // int leftPart = longestSubstring(s.substring(0, i), k);
        // int rightPart = longestSubstring(s.substring(i + 1), k);
        // return Math.max(leftPart, rightPart);
        // }
        // }

        // return s.length();

        // --------------------------------------------------

        return helper(s, k, 0, s.length());

    }

    public int helper(String s, int k, int start, int end) {
        if (end - start < k) {
            return 0;

        }

        int[] arr = new int[26];
        for (int i = start; i < end; i++) {
            char ch = s.charAt(i);
            arr[ch - 'a']++;
        }

        for (int i = start; i < end; i++) {
            char ch = s.charAt(i);
            if (arr[ch - 'a'] < k) {
                int j = i + 1;
                while (j < end && arr[s.charAt(j) - 'a'] < k) {
                    j++;
                }

                return Math.max(helper(s, k, start, i), helper(s, k, j, end));
            }
        }
        return end - start;
    }
}