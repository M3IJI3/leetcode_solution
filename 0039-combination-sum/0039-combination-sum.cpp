class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        backtrack(result, path, candidates, target, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& path, const vector<int>& candidates, int target, int start){
        if(target == 0){
            result.push_back(path);
            return;
        }

        for(int i = start ; i < candidates.size() ; i++){
            if(candidates[i] > target) break;
            path.push_back(candidates[i]);
            backtrack(result, path, candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};