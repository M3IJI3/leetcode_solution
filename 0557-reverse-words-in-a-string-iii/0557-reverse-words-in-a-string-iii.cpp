class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string word;
        istringstream iss(s);

        while(iss >> word){
            reverse(word.begin(), word.end());
            ans += word + " ";
        }

        // 去掉最后多余的空格
        if(!ans.empty()) ans.pop_back();
        return ans;
    }
};