class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;      // 最长回文子串的起始位置
        int maxLen = 0;     // 最长回文子串的长度

        for (int i = 0; i < s.size(); i++) {
            // 奇数长度的回文，以 i 为中心扩展
            expandAroundCenter(s, i, i, start, maxLen);

            // 偶数长度的回文，以 i 和 i+1 为中心扩展
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen); // 返回最长回文子串
    }

private:
    void expandAroundCenter(string& s, int left, int right, int& start, int& maxLen) {
        // 向两边扩展，只要左右字符相等，就继续扩展
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        // 此时回文区间是 (left+1, right-1)，长度是 right - left - 1
        int len = right - left - 1;
        if (len > maxLen) {
            maxLen = len;          // 更新最长长度
            start = left + 1;      // 更新起始位置
        }
    }
};
