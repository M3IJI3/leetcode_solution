class Solution {
public:
    const int dirs[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = -1;  // ★ 用 -1 标记已访问

        int steps = 1;  // 起点算一步

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front(); q.pop();

                if (x == n - 1 && y == n - 1) return steps;

                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] != 0) continue;  // 不是 0 就跳过（墙或已访问）

                    grid[nx][ny] = -1;  // 标记已访问
                    q.push({nx, ny});
                }
            }
            steps++;  // ★ 每层步数 +1
        }

        return -1;
    }
};