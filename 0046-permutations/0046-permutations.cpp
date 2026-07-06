class Solution {
    vector<vector<int>> ans;
    vector<bool> visited; 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        visited = vector<bool>(n, false);
        vector<int> path;
        dfs(nums, path); 
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& path){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(visited[i]) continue;

            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path);
            path.pop_back();
            visited[i] = false;
        }
    }
};