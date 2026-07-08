class Solution {
public:
    const int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(auto& d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(dist[nx][ny] != -1) continue;
                if(grid[nx][ny] != 1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }

        int mins = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) return -1;
                mins = max(mins, dist[i][j]);
            }
        }
        return mins;
    }
};

// 2 1 1 
// 0 1 1
// 1 0 1