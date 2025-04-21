class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp;

        for(string word: words){
            temp += word;
            if(temp == s){
                return true;
            }
        }
        return false;
    }
};