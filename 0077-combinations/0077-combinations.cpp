class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;

        vector<int> path;
        vector<bool> visited(n , false);

        vector<int> nums;
        for(int i = 1 ; i <= n ; i++){
            nums.push_back(i);
        }

        backtrack(result, visited, nums, path, k);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<bool>& visited, const vector<int>& nums, vector<int>& path, int k){
        if(path.size() == k){
            result.push_back(path);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(visited[i]) return;

            path.push_back(nums[i]);
            visited[i] = true;

            backtrack(result, visited, nums, path, k);

            visited[i] = false;
            path.pop_back();
        }
    }
};