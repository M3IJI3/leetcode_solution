class Solution {
public:
    string reformat(string s) {
        string letters;
        string digits;

        for(char c : s){
            if(c < 'a') digits += c;
            else letters += c; 
        }

        int diff = letters.size() - digits.size();

        if(abs(diff) > 1) return "";

        int i = 0, j = 0;
        string ans;
        while(i < letters.size() || j < digits.size()){
            if(letters.size() > digits.size()){
                if(i < letters.size()) ans += letters[i++];
                if(j < digits.size()) ans += digits[j++];
            } else {
                if(j < digits.size()) ans += digits[j++];
                if(i < letters.size()) ans += letters[i++];
            }
        }
        return ans;
    }
};