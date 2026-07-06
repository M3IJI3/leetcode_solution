class Solution {
    vector<vector<int>> ans;
    vector<bool> used;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        used = vector<bool>(10, false);
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
            if(used[i]) continue;
            used[i] = true;
            path.push_back(i);
            dfs(n, k, sum + i, path, i + 1);
            path.pop_back();
            used[i] = false;
        }
    }
};