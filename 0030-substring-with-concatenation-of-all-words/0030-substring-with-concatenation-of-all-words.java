public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) {
            return result;
        }

        int wordLen = words[0].length();    // 单词的长度
        int wordCount = words.length;       // 单词的个数
        int totalLen = wordLen * wordCount; // 窗口长度
        
        // 构建目标单词频率表
        Map<String, Integer> wordMap = new HashMap<>();
        for (String word : words) {
            wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
        }

        // 从每个可能的起点开始滑动窗口
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i;  // 初始化窗口的左右边界
            int matchedCount = 0;     // 当前匹配的单词数量
            Map<String, Integer> currentMap = new HashMap<>();

            while (right + wordLen <= s.length()) {
                // 提取窗口内的单词
                String word = s.substring(right, right + wordLen);
                right += wordLen;

                // 如果单词在 words 中
                if (wordMap.containsKey(word)) {
                    currentMap.put(word, currentMap.getOrDefault(word, 0) + 1);

                    // 如果当前单词频率合法
                    if (currentMap.get(word) <= wordMap.get(word)) {
                        matchedCount++;
                    } else {
                        // 频率超出，缩小窗口
                        while (currentMap.get(word) > wordMap.get(word)) {
                            String leftWord = s.substring(left, left + wordLen);
                            left += wordLen;
                            currentMap.put(leftWord, currentMap.get(leftWord) - 1);

                            // 这里的 if 判断条件要弄清楚
                            // "<" 说明有效匹配的单词少一个 所以 macthedCount 要减少1
                            if (currentMap.get(leftWord) < wordMap.get(leftWord)) {
                                matchedCount--;
                            }
                        }
                    }

                    // 如果窗口匹配完整，记录起始索引
                    if (matchedCount == wordCount) {
                        result.add(left);
                    }
                } else {
                    // 如果单词不在 words 中，重置窗口
                    currentMap.clear();
                    matchedCount = 0;
                    left = right;
                }
            }
        }

        return result;
    }
}
