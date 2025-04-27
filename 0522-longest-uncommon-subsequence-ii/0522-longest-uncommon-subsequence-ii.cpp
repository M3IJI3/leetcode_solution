class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;

        for(int i = 0 ; i < strs.size() ; i++){
            bool isSpecial = true;
            for(int j = 0 ; j < strs.size() ; j++){
                if(i == j) continue;
                if(isSubsequence(strs[i], strs[j])){
                    isSpecial = false;
                    break;
                }
            }
            if(isSpecial){
                maxLen = max(maxLen, (int)strs[i].size());
            }
        }
        return maxLen;
    }
// 定义函数判断s1是否为s2的子序列
private:
    bool isSubsequence(string& s1, string& s2) {
        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]) i++;
            j++;
        }
        return i == s1.size();
    }
};