class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        
        string ans;
        int maxLen = -1;
        for(int i = 0 ; i < dictionary.size() ; i++){
            if(isSubsequence(dictionary[i], s)){
                // 记录当前字符串的长度
                int currLen = dictionary[i].size();
                // 更新最长字符串长度
                if(currLen > maxLen){
                    ans = dictionary[i]; 
                    maxLen = currLen;
                }
            } 
        }
        return ans;
    }
private:
    bool isSubsequence(string& s1, string& s2){
        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]) i++;
            j++;
        }
        return i == s1.size();
    }
};