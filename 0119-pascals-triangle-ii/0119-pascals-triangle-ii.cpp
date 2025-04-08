class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> ans(2, vector<int>(n + 1, 1));

        for(int i = 0 ; i <= n ; i++){
            for(int j = 1 ; j < i ; j++){
                ans[i % 2][j] = ans[(i - 1) % 2][j - 1] + ans[(i - 1) % 2][j];
            }
        }
        return ans[n % 2];
    }
};