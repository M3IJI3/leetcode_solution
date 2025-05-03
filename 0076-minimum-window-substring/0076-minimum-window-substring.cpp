// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if(s.empty() || t.empty()) return "";

//         unordered_map<char, int> need, window;
//         for(char c : t) need[c]++;

//         int left = 0, right = 0;
//         int valid = 0; // 满足的字符种类
//         int start = 0, len = INT_MAX;

//         while(left < s.size()){
//             char c = s[right];
//             right++;

//             // 如果是需要的字符, 加入window中
//             if(need.count(c)){
//                 window[c]++;
//                 if(window[c] == need[c]) valid++;
//             }

//             // 尝试收缩窗口
//             while(valid == need.size()){
//                 // 更新最小窗口
//                 if(right - left < len){
//                     start = left;
//                     len = right - left;
//                 }

//                 char d = s[left];
//                 left++;

//                 if(need.count(d)){
//                     if(window[d] == need[d]) valid--;
//                     window[d]--;
//                 }
//             }
//         }

//         return len == INT_MAX ? "" : s.substr(start, len);
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";

        unordered_map<char, int> need, window;
        for(char& c : t) need[c]++;  // 统计目标字符串字母出现的频率

        int left = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        for(int right = 0 ; right < s.size() ; right++){
            char letter = s[right];

            if(need.count(letter)){
                window[letter]++;
                if(window[letter] == need[letter]) valid++;
            }

            // 开始收缩窗口
            while(valid == need.size()){
                // 更新最小窗口
                if(right - left + 1 < len){
                    start = left;
                    len = right - left + 1;
                }

                char d = s[left];
                left++;

                if(need.count(d)){
                    if(window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};













