class Solution {
    int minLen = INT_MAX;
    int maxLen = 0;
    unordered_set<string> words;
    vector<string> ans;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto& word : wordDict){
            minLen = min(minLen, (int)word.size());
            maxLen = max(maxLen, (int)word.size());
            words.insert(word);
        }
        vector<string> path;
        dfs(s, path, 0);
        return ans;
    }

    void dfs(string& s, vector<string>& path, int index){
        if(index == s.size()){
            string temp = "";
            for(int i = 0 ; i < path.size() ; i++){
                if(i == 0) temp.append(path[i]);
                else temp.append(" " + path[i]);
            }
            ans.push_back(temp);
            return;
        }

        for(int len = minLen ; len <= maxLen && len + index <= s.size() ; len++){
            string sub = s.substr(index, len);
            if(!words.count(sub)) continue;

            path.push_back(sub);
            dfs(s, path, len + index);
            path.pop_back();
        }
    }
};