class Solution {
public:
    bool splitString(string s) {
        vector<long long> path;
        return dfs(s, path, 0);
    }

    bool dfs(string& s, vector<long long>& path, int index){
        if(index == s.size()){
            return path.size() >= 2;
        }

        long long num = 0;
        for(int i = index ; i < s.size() ; i++){
            num = num * 10 + (s[i] - '0');

            if(num > LLONG_MAX / 10) break;

            if(!path.empty() && path.back() - num != 1) continue;
            path.push_back(num);
            if(dfs(s, path, i + 1)) return true;
            path.pop_back();
        }
        return false;
    }
};