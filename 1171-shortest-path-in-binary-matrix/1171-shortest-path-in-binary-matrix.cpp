class Solution {
public:
    const int dirs[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1;

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            if(x == n - 1 && y == n - 1) return dist[x][y];
            for(auto& d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(grid[nx][ny] == 1) continue;
                if(dist[nx][ny] != -1) continue;
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
        return -1;
    }
};