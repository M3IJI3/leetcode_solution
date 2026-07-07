class Solution {
    int m, n;
    vector<vector<int>> memo;
    int dirs[3][2] = {{-1,1}, {0,1}, {1,1}};

public:
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1)); // -1 表示未计算过

        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, dfs(grid, i, 0));
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (memo[x][y] != -1) return memo[x][y]; // 记忆化：已经算过直接返回

        int best = 0; // 走不动了，返回0步
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (grid[nx][ny] <= grid[x][y]) continue; // 必须严格更大

            best = max(best, 1 + dfs(grid, nx, ny));
        }

        return memo[x][y] = best;
    }
};