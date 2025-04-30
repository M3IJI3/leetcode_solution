class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // 把T换成F 或者把F换成T
        // 最多可以换 k 次

        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for(int right = 0 ; right < answerKey.size() ; right++){
            freq[answerKey[right] - 'A']++;
            maxFreq = max(maxFreq, freq[answerKey[right] - 'A']); 

            // 收缩左边界
            // 非出现次数最多的字符仍然大于k
            while((right - left + 1) - maxFreq > k){
                freq[answerKey[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};