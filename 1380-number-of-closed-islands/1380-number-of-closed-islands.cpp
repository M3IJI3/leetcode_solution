class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 2;
                    bool isClosed = true;

                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        if(x == 0 || x == m - 1 || y == 0 || y == n - 1) isClosed = false;
                        for(auto& d : dirs){
                            int nx = x + d[0], ny = y + d[1];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if(grid[nx][ny] != 0) continue;
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                    if(isClosed) ans++;
                }
            }
        }
        return ans;
    }
};