class Solution {
    public String longestNiceSubstring(String s) {
        int n = s.length();
        int maxPos = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int lower = 0;
            int upper = 0;
            for (int j = i; j < n; j++) {
                if (Character.isLowerCase(s.charAt(j))) {
                    lower |= 1 << (s.charAt(j) - 'a'); // 计算出对于'a'的偏移量
                } else {
                    upper |= 1 << (s.charAt(j) - 'A'); // 计算出对于'A'的偏移量
                }
                if (lower == upper && j - i + 1 > maxLen) {
                    maxPos = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substring(maxPos, maxPos + maxLen);
    }
}