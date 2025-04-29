class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0, maxLen = 0;

        for(int right = 0 ; right < s.size() ; right++){
            freq[s[right]]++;

            // 如果当前字符重复, 缩小窗口直到不重复
            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }

            // 更新maxLen
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};