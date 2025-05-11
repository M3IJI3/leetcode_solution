class Solution {
public:
    string reverseWords(string s) {
        cleanSpaces(s);
        reverse(s.begin(), s.end());

        int start = 0;
        for(int end = 0 ; end <= s.size() ; end++){
            if(end == s.size() || s[end] == ' '){
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
private:
    void cleanSpaces(string& s){
        int i = 0, j = 0;
        while(j < s.size()){
            // 跳过前导空格
            while(j < s.size() && isspace(s[j])) j++;
            // 复制非空格字符
            while(j < s.size() && !isspace(s[j])) s[i++] = s[j++];
            // 跳过空格并只保留一个空格
            while(j < s.size() && isspace(s[j])) j++;
            if(j < s.size()) s[i++] = ' ';
        }

        s.resize(i); // 移除尾部多余字符
    }
};


// istringstream iss(s);
// string word, res;
// while (iss >> word) {
//     if (!res.empty()) res = " " + res;
//     res = word + res;
// }
// return res;
