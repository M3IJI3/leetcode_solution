class Solution {
    vector<int> memo;
public:
    int climbStairs(int n) {
        memo.resize(n + 1);
        return dfs(n);
    }

    int dfs(int i){
        if(i <= 1) return 1;
        int& res = memo[i];
        if(res) return res;
        return res = dfs(i - 1) + dfs(i - 2);
    }
};