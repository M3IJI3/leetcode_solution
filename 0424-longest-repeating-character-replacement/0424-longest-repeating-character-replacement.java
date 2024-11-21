class Solution {
    public int characterReplacement(String s, int k) {
        int[] arr = new int[26];
        int res = 0;
        int max = 0;

        int n = s.length();
        int left = 0;
        for (int right = 0; right < n; right++) {
            // 计算每个字母的个数
            arr[s.charAt(right) - 'A']++;

            // 更新出现最多次数的字母
            max = Math.max(max, arr[s.charAt(right) - 'A']);

            if (right - left + 1 - max > k) {
                arr[s.charAt(left) - 'A']--;
                left++;
            }
            res = Math.max(res, right - left + 1);
        }
        return res;
    }
}