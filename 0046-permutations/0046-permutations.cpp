class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        
        vector<int> path;
        backtrack(result, visited, path, nums);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<bool>& visited, vector<int>& path, vector<int>& nums){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(!visited[i]){
                path.push_back(nums[i]);
                visited[i] = true;

                backtrack(result, visited, path, nums);

                path.pop_back();
                visited[i] = false;
            }   
        }
    }
};