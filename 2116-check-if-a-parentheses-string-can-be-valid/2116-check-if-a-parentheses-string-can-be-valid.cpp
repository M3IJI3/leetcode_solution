class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 != 0) return false;

        bool isValid = false;
        string path;
        backtrack(s, locked, path, 0, isValid);
        return isValid;
    }
private:
    void backtrack(string& s, string& locked, string& path, int start, bool& isValid){
        if(isValid) return;

        if(path.size() == s.size()){
            if(isValidParentheses(path)){
                isValid = true;
            }
            return;
        }

        if(locked[start] == '1'){
            path.push_back(s[start]);
            backtrack(s, locked, path, start + 1, isValid);
            path.pop_back();
        } else {
            path.push_back('(');
            backtrack(s, locked, path, start + 1, isValid);
            path.pop_back();

            path.push_back(')');
            backtrack(s, locked, path, start + 1, isValid);
            path.pop_back();
        }
    }

// 检查当前是否为valid的括号序列
private:
    bool isValidParentheses(string& parenthes){
        unordered_map<char, char> map = { {')', '('} };
        stack<char> stk;

        for(char c: parenthes){
            if(!stk.empty() && map[c] == stk.top()){
                stk.pop();
                continue;
            }
            stk.push(c);    
        }
        return stk.empty();
    }
};