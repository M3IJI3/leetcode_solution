class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();

        while(i < n){
            int lineLen = words[i].size();
            int j = i + 1; // 下一个不能放下的单词的索引

            // 找出能放下的单词
            while(j < n && lineLen + words[j].size() + (j - i) <= maxWidth){
                lineLen += words[j].size();
                j++;
            }

            int wordCount = j - i;
            int totalSpaces = maxWidth - lineLen;
            string line;

            // 最后一行 或 某一行只有一个单词 -> 左对齐
            if(j == n || wordCount == 1){
                for(int k = i ; k < j ; k++){
                    line += words[k];
                    if(k != j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                // 其他行平均分配空格
                int spacePerSlot = totalSpaces / (wordCount - 1);
                int extraSpaces = totalSpaces % (wordCount - 1); // 余数就是多出来的空格数 (余数肯定小于空隙数)

                for(int k = i ; k < j - 1 ; k++){
                    line += words[k];
                    line += string(spacePerSlot + (k - i < extraSpaces ? 1 : 0), ' '); // k - i 表示第几个空隙
                }
                line += words[j - 1]; // 最后一个单词不加空格
            }

            result.push_back(line);
            i = j; // 处理下一行
        }

        return result;
    }
};