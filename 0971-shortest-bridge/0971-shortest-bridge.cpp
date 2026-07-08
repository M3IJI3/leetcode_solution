class Solution {
    int n;
    queue<pair<int, int>> q;
    const int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    return bfs(grid);
                }
            }
        }
        return 0;
    }

    int bfs(vector<vector<int>>& grid){
        int res = -1;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i = 0 ; i < size ; i++){
                auto [x, y] = q.front(); q.pop();
                for(auto& d : dirs){
                    int nx = x + d[0], ny = y + d[1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(grid[nx][ny] == -1) continue;
                    if(grid[nx][ny] == 1) return res;
                    grid[nx][ny] = -1;
                    q.push({nx, ny});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || x >= n || y < 0 || y >= n) return;
        if(grid[x][y] != 1) return;
        grid[x][y] = -1;
        q.push({x, y});
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1); 
    }
};