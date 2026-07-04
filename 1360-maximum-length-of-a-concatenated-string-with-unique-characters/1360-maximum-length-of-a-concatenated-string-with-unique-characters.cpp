class Solution {
    int ans = 0;
public:
    int maxLength(vector<string>& arr) {
        string path = "";
        dfs(arr, path, 0);
        return ans;
    }

    void dfs(vector<string>& arr, string& path, int i){
        if(i == arr.size()){
            ans = max(ans, (int)path.size());
            return;
        }

        dfs(arr, path, i + 1);
        if(ok(path, arr[i])){
            string newPath = path + arr[i];
            dfs(arr, newPath, i + 1);
        }

    }

    bool ok(const string& path, const string& s){
        int mask = 0;
        for(char c : path){
            int bit = (1 << (c - 'a'));
            if(mask & bit) return false;
            mask |= bit;
        }

        for(char c : s){
            int bit = (1 << (c - 'a'));
            if(mask & bit) return false;
            mask |= bit;
        }
        return true;
    }
};