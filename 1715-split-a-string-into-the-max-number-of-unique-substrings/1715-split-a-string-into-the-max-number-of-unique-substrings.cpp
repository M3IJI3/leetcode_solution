class Solution {
    int maxLen = 0;
    unordered_set<string> seen;
public:
    int maxUniqueSplit(string s) {
        vector<string> path;
        dfs(s, path, 0);
        return maxLen;
    }

    void dfs(string& s, vector<string>& path, int index){
        if(index == s.size()){
            maxLen = max(maxLen, (int)path.size());
            return;
        }    

        if(path.size() + (s.size() - index) <= maxLen) return;

        for(int i = index ; i < s.size() ; i++){
            string sub = s.substr(index, i - index + 1);
            if(seen.count(sub)) continue;

            seen.insert(sub);
            path.push_back(sub);
            dfs(s, path, i + 1);
            path.pop_back();
            seen.erase(sub);
        }
    }
};