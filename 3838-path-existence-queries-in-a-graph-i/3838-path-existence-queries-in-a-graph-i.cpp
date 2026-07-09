class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> idx;
        for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i + 1] - nums[i] > maxDiff){
                idx.push_back(i);
            }
        }

        vector<bool> ans(queries.size());
        for(int i = 0 ; i < queries.size() ; i++){
            auto& q = queries[i];
            ans[i] = ranges::lower_bound(idx, q[0]) == ranges::lower_bound(idx, q[1]);
        }
        return ans;
    }
};