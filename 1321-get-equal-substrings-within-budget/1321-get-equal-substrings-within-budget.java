class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        // ERROR: 只考虑了一次遍历的情况
        // int len = 0;
        // for(int i = 0 ; i < s.length() ; i++)
        // {
        // if(Math.abs(s.charAt(i) - t.charAt(i)) <= maxCost)
        // {
        // maxCost -= Math.abs(s.charAt(i) - t.charAt(i));
        // len++;
        // }
        // }
        // return len;

        int left = 0, right = 0;
        int currentCost = 0, maxLength = 0;

        while (right < s.length()) {
            currentCost += Math.abs(s.charAt(right) - t.charAt(right));

            while (currentCost > maxCost) {
                currentCost -= Math.abs(s.charAt(left) - t.charAt(left));
                left++;
            }

            maxLength = Math.max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
}