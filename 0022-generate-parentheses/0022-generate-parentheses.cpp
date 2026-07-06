class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string path = "";
        dfs(path, n, n);
        return ans;
    }

    void dfs(string path, int left, int right){
        if(!left && !right){
            ans.push_back(path);
        }

        if(left > right) return;

        if(left > 0) dfs(path + '(', left - 1, right);
        if(right > 0) dfs(path + ')', left, right - 1);
    }
};