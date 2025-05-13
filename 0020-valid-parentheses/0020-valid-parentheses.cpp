class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> stk;
        for(char c : s){
            if(!stk.empty() && map[c] == stk.top()){
                stk.pop();
                continue;
            }
            stk.push(c);
        }
        return stk.empty();
    }
};