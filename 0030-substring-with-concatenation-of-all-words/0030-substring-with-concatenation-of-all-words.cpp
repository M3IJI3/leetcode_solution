// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> ans;
//         if(words.empty() || s.empty()) return ans;

//         int wordLen = words[0].size();         // 计算一个word长度
//         int totalLen = wordLen * words.size(); // 计算总长度

//         unordered_map<string, int> wordFreq;
//         for(string& word : words) wordFreq[word]++;

//         // 枚举所有起点偏移: 0 到 wordLen - 1
//         for(int i = 0 ; i < wordLen ; i++){
//             int left = i, count = 0;
//             unordered_map<string, int> windowFreq;

//             for(int right = i ; right + wordLen <= s.size() ; right += wordLen){
//                 string word = s.substr(right, wordLen); // 截取单词

//                 // 合法词
//                 if(wordFreq.count(word)){
//                     windowFreq[word]++;
//                     count++;

//                     // 多了 缩小窗口
//                     while(windowFreq[word] > wordFreq[word]){
//                         string leftWord = s.substr(left, wordLen);
//                         windowFreq[leftWord]--;
//                         left += wordLen;
//                         count--;
//                     }

//                     if(count == words.size()) ans.push_back(left);

//                 } else {
//                     // 不合法词 清空窗口
//                     windowFreq.clear();
//                     count = 0;
//                     left = right + wordLen;
//                 }
//             }
//         }
//         return ans;
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 class Solution {
 public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.empty() || words.empty()) return ans;

        unordered_map<string, int> wordFreq;
        for(string& word : words) wordFreq[word]++;

        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();

        int left = 0;
        string window;
        unordered_map<string, int> windowFreq;
        for(int right = 0 ; right < s.size() ; right++){
            window += s[right];

            while(window.size() > totalLen){
                left++;
                window = window.substr(1);
            }

            if(window.size() == totalLen){
                for(int i = 0 ; i < window.size() ; i += wordLen){
                    string temp = window.substr(i, wordLen);
                    windowFreq[temp]++;
                }

                if(windowFreq == wordFreq){
                    ans.push_back(left);
                }

                windowFreq.clear();
            }
        }
        return ans;
    }
 };
