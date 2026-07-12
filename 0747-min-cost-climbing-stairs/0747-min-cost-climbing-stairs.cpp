class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1, -1);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if(i <= 1) return 0;
            int &res = memo[i];
            if(res != -1) return res;
            return res = min(dfs(i - 1) + cost[i - 1], dfs(i - 2) + cost[i - 2]);
        };
        return dfs(n);
    }
};