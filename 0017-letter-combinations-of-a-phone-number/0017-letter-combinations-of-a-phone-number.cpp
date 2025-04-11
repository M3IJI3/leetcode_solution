class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        unordered_map<char, string> phoneMap = {
            {'2' , "abc" },  {'3' , "def"},
            {'4' , "ghi" },  {'5' , "jkl"},  {'6' , "mno" },
            {'7' , "pqrs"},  {'8' , "tuv"},  {'9' , "wxyz"} 
        };

        vector<string> result;
        string path;

        backtrack(digits, 0, path, result, phoneMap);
        return result;
    }
private: 
    void backtrack(const string& digits, int index, string& path, vector<string>& result, unordered_map<char, string>& phoneMap) {
        if(index == digits.size()){
            result.push_back(path);
            return;
        }

        char digit = digits[index];
        const string& letters = phoneMap[digit];

        for(char letter : letters){
            path.push_back(letter);
            backtrack(digits, index + 1, path, result, phoneMap);
            path.pop_back();
        }
    }
};