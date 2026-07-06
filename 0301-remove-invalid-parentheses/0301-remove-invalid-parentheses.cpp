class Solution {
    vector<string> ans;
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(char c : s){
            if(c == '('){
                left++;
            } else if(c == ')'){
                if(left > 0) left--;
                else right++;
            }
        }

        dfs(s, left, right, 0);
        return ans;
    }

    void dfs(string& s, int left, int right, int start){
        if(!left && !right){
            if(isValid(s)){
                ans.push_back(s);
            }
            return;
        }

        for(int i = start ; i < s.size() ; i++){
            if(i > start && s[i] == s[i - 1]) continue;

            if(s[i] == '(' && left > 0){
                string next = s.substr(0, i) + s.substr(i + 1);
                dfs(next, left - 1, right, i);
            }

            if(s[i] == ')' && right > 0){
                string next = s.substr(0, i) + s.substr(i + 1);
                dfs(next, left, right - 1, i);
            }
        }
    }

    bool isValid(const string& s){
        int cnt = 0;
        for(char c : s){
            if(c == '(') cnt++;
            else if(c == ')'){
                cnt--;
                if(cnt < 0) return false;
            }
        }
        return true;
    }
};