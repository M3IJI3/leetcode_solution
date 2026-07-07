class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        vector<int> path;
        dfs(nums, path, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& path, int index){
        ans.push_back(path);
        if(index == nums.size()) return;
        for(int i = index ; i < nums.size() ; i++){
            if(i > index && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            dfs(nums, path, i + 1);
            path.pop_back();
        }
    }
};