class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> f(n + 1);
        for(int i = 1 ; i <= n ; i++){
            int res = INT_MAX;
            for(int j = max(i - 3, 0) ; j < i ; j++){
                res = min(res, f[j] + (i - j) * (i - j));
            }
            f[i] = res + costs[i - 1];
        }
        return f[n];
    }
};