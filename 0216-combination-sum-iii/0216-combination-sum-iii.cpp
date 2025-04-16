// 1 ~ 9里面选k个数, 加起来等于n
// 每个数只能用一次
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1 ; i <= 9 ; i++){
            nums.push_back(i);
        }

        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, result, path, k, n, 0);
        return result;
    }

    void backtrack(const vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int k , int n, int start){
        if(n == 0 && path.size() == k){
            result.push_back(path);
            return;
        }

        for(int i = start ; i < nums.size() ; i++){
            path.push_back(nums[i]);
            backtrack(nums, result, path, k, n - nums[i], i + 1);
            path.pop_back();
        }
    }
};