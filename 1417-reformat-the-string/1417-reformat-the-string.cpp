class Solution {
public:
    string reformat(string s) {
        string letters;
        string digits;

        for(char c : s){
            if(isdigit(c)) digits += c;
            else letters += c; 
        }

        if(abs((int)letters.size() - (int)digits.size()) > 1) return "";

        if(letters.size() < digits.size()) swap(letters, digits);

        int i = 0, j = 0;
        string ans;
        while(i < letters.size() || j < digits.size()){
            if(i < letters.size()) ans += letters[i++];
            if(j < digits.size()) ans += digits[j++];
        }
        return ans;
    }
};

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// class Solution {
// public:
//     string reformat(string s) {
//         string letters, digits;
//         for (char c : s) {
//             if (isalpha(c)) letters += c;
//             else digits += c;
//         }

//         if (abs((int)letters.size() - (int)digits.size()) > 1) return "";

//         // 让 letters 始终是更多的一方
//         if (digits.size() > letters.size()) swap(letters, digits);

//         string res;
//         for (int i = 0; i < s.size(); ++i) {
//             if (i % 2 == 0) res += letters[i / 2];
//             else res += digits[i / 2];
//         }
//         return res;
//     }
// };
