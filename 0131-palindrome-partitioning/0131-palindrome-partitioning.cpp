class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, path, 0);
        return ans;
    }

    void dfs(string& s, vector<string>& path, int index){
        if(index == s.size()){
            ans.push_back(path);
            return;
        }

        for(int i = index ; i < s.size() ; i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                dfs(s, path, i + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
};