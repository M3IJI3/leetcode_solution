class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[3][2] = {{-1,1}, {0,1}, {1,1}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;

        // 起点：第0列的所有行
        for (int i = 0; i < m; i++) {
            q.push({i, 0});
            visited[i][0] = true;
        }

        int ans = 0;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            ans = max(ans, y);

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (visited[nx][ny]) continue;
                if (grid[nx][ny] <= grid[x][y]) continue; // 必须严格更大

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        return ans;
    }
};