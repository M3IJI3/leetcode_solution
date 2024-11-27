class Solution {
    public int numberOfSubstrings(String s) {
        // 考虑到子串数量计算的问题
        // Map<Character, Integer> window = new HashMap<>(); // 记录窗口内字母出现频率
        // window.put('a', 0);
        // window.put('b', 0);
        // window.put('c', 0);

        // int left = 0;
        // int result = 0;
        // int count = 0;
        // for (int right = 0; right < s.length(); right++) {
        // char rightChar = s.charAt(right);
        // window.put(rightChar, window.get(rightChar) + 1);

        // while (window.get('a') >= 1 && window.get('b') >= 1 && window.get('c') >= 1)
        // {
        // result += s.length() - right;

        // // 移除左边界字符
        // char leftChar = s.charAt(left);
        // window.put(leftChar, window.get(leftChar) - 1);
        // left++;
        // }
        // }

        // return result;
        // ------------------------------------------------------
        int[] count = new int[3];
        int left = 0;
        int result = 0;

        for (int right = 0; right < s.length(); right++) {
            // 统计右边界字符
            count[s.charAt(right) - 'a']++;

            // 收缩左边界，直到包含所有字符
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s.charAt(left) - 'a']--;
                left++;
            }

            // 计算以右边界结尾的符合条件的子串数量
            result += left;
        }

        return result;
    }
}