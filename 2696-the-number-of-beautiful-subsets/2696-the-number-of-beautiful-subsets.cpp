class Solution {
    int ans = 0;
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> path;
        dfs(nums, path, k, 0);
        return ans - 1;
    }

    void dfs(vector<int>& nums, vector<int>& path, int k, int index){
        if(index == nums.size()){
            ans++;
            return;
        }

        dfs(nums, path, k, index + 1);

        bool canChoose = true;
        for(int p : path){
            if(abs(p - nums[index]) == k){
                canChoose = false;
                break;
            }
        }

        if(canChoose){
            path.push_back(nums[index]);
            dfs(nums, path, k, index + 1);
            path.pop_back();
        }
    }
};