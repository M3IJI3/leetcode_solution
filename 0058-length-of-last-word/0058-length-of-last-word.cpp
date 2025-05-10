class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = 0;
        for(int i = s.size() - 1 ; i >= 0 ; i--){
            if(!isspace(s[i])){
                pos = i;
                break;
            }
        }

        int ans = 0;
        while(!isspace(s[pos])){
            ans++;
            pos--;
        }  

        return ans; 
    }
};