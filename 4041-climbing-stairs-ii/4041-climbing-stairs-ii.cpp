class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> memo(n + 1);
        
        auto dfs = [&](this auto&& dfs, int i) -> int{
            if(i == 0) return 0;
            int &res = memo[i];
            if(res) return res;
            res = INT_MAX;
            for(int j = max(i-3, 0); j < i ; j++){
                res = min(res, dfs(j) + (i - j) * (i - j));
            }
            res += costs[i - 1];
            return res;
        };
        return dfs(n);
    }
};