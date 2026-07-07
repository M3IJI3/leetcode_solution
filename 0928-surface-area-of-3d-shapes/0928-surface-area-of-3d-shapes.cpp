class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    ans += grid[i][j] * 6;

                    ans -= (grid[i][j] - 1) * 2;

                    if (i + 1 < n) {
                        ans -= min(grid[i][j], grid[i + 1][j]) * 2;
                    }
                    if (j + 1 < n) {
                        ans -= min(grid[i][j], grid[i][j + 1]) * 2;
                    }
                }
            }
        }
        return ans;
    }
};