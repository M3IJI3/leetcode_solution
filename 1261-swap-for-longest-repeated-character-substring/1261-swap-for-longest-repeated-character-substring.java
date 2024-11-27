class Solution {
    public int maxRepOpt1(String text) {
        // Map<Character, Integer> charCount = new HashMap<>();
        // // 记录每个字符在整个字符串中的总出现次数
        // for (char c : text.toCharArray()) {
        //     charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        // }

        // int left = 0, maxFreq = 0, maxLength = 0;
        // Map<Character, Integer> windowCount = new HashMap<>();

        // for (int right = 0; right < text.length(); right++) {
        //     char rightChar = text.charAt(right);
        //     windowCount.put(rightChar, windowCount.getOrDefault(rightChar, 0) + 1);
        //     maxFreq = Math.max(maxFreq, windowCount.get(rightChar)); // 窗口内最多的字符频率

        //     // 如果窗口无效（需要替换的字符数 > 1）
        //     while ((right - left + 1) - maxFreq > 1) {
        //         char leftChar = text.charAt(left);
        //         windowCount.put(leftChar, windowCount.get(leftChar) - 1);
        //         if (windowCount.get(leftChar) == 0) {
        //             windowCount.remove(leftChar);
        //         }
        //         left++;
        //     }

        //     // 更新最大长度（考虑全局字符总数限制）
        //     maxLength = Math.max(maxLength, Math.min(right - left + 1, charCount.get(rightChar)));
        // }

        // return maxLength;

        // --------------------------------------------------------------

        Map<Character, Integer> charCount = new HashMap<>();
        // 记录每个字符在整个字符串中的总出现次数
        for (char c : text.toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }

        int maxLen = 0;

        for(char target: charCount.keySet())
        {
            int left = 0, right = 0, otherCount = 0;
            while(right < text.length())
            {
                if(text.charAt(right) != target)
                {
                    otherCount++;
                }

                while(otherCount > 1)
                {
                    if(text.charAt(left) != target)
                    {
                        otherCount--;
                    }
                    left++;
                }

                // 更新最大长度，不能超过目标字符的总频率
                maxLen = Math.max(maxLen, Math.min(right - left + 1, charCount.get(target)));
                right++;
            }
        }
        return maxLen;
    }
}