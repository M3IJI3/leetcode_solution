class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) ans++;
                }
            }
        }
        return ans;
    }

    bool dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();

        // ★ 如果碰到边界 → 不封闭
        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
            return false;
        }

        grid[x][y] = 2;  // 标记已访问

        int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        bool closed = true;

        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (grid[nx][ny] != 0) continue;

            // ★ 如果子 DFS 返回 false → 整个岛屿不封闭
            if (!dfs(grid, nx, ny)) {
                closed = false;
            }
        }

        return closed;
    }
};