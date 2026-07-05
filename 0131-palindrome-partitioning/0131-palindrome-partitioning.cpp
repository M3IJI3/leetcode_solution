class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, path, 0, 0);
        return ans;
    }

    void dfs(string& s, vector<string>& path, int i, int start){
        if(i == s.size()){
            ans.push_back(path);
            return;
        }

        if(i < s.size() - 1){
            dfs(s, path, i + 1, start);
        }

        if(isPalindrome(s, start, i)){
            path.push_back(s.substr(start, i - start + 1));
            dfs(s, path, i + 1, i + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string& s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
};