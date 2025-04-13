class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size() , false);

        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, result, path, visited);

        // set<vector<int>> uniqueSet(result.begin(), result.end());
        // vector<vector<int>> ans(uniqueSet.begin(), uniqueSet.end());
        // return ans;

        return result;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& visited){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        // 先排序 这样重复的元素会相邻
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(visited[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            path.push_back(nums[i]);
            visited[i] = true;

            backtrack(nums, result, path, visited);

            visited[i] = false;
            path.pop_back();
        }
    }
};