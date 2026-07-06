class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(n, k, 0, path, 1);
        return ans;
    }

    void dfs(int n, int k, int sum, vector<int>& path, int index){
        if(path.size() == k){
            if(sum == n){
                ans.push_back(path);
            }
            return;
        }

        if(sum > n) return;

        for(int i = index ; i <= 9 ; i++){
            path.push_back(i);
            dfs(n, k, sum + i, path, i + 1);
            path.pop_back();
        }
    }
};