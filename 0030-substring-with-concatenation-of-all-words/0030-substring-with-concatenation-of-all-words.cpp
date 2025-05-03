// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         // 逻辑混乱
//         // // 将 words 放入 map 中计算每个 word 出现的频率
//         // unordered_map<string, int> freq;
//         // for(string word : words){
//         //     freq[word]++;
//         // }

//         // // 维护一个窗口
//         // int left = 0;
//         // int word_len = words[0].size(); // 找到 word 的长度 (因为每个单词长度相同)
//         // string window;
        
//         // vector<int> ans;
//         // for(int right = 0 ; right < s.size() ; right++){
//         //     window += s[right];

//         //     while(window.size() > word_len){
//         //         window = window.substr(1);
//         //         left++;
//         //     }

//         //     // 找到窗口内每个单词出现的频率
//         //     if(window.size() == word_len){
//         //         unordered_map<string, int> window_freq;
//         //         for(int i = 0 ; i < window.size() ; i += word_len){
//         //             string str = window.substr(i, i + word_len);
//         //             window_freq[str]++;
//         //         }

//         //         if(window_freq == freq){
//         //             ans.push_back(left);
//         //         } 

//         //         window_freq.clear();
//         //     }
//         // }
//         // return ans;
//         
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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
