class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(n, k, path, 1);
        return ans;
    }

    void dfs(int n, int k, vector<int>& path, int start){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }

        for(int i = start ; i <= n ; i++){
            path.push_back(i);
            dfs(n, k, path, i + 1);
            path.pop_back();
        }
    }
};