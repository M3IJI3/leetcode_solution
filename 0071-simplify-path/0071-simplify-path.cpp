class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        istringstream iss(path);
        string token;

        while(getline(iss, token, '/')){
            if(token == "" || token == ".") continue;
            if(token == ".."){
                if(!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }

        string ans;
        for(int i = 0 ; i < stack.size() ; i++){
            ans += "/" + stack[i];
        }

        return ans.empty() ? "/" : ans;
    }
};