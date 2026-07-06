class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int m = grid.size(), n = grid[0].size();
        
        int islands = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    islands++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();

                        for(auto& d : dirs){
                            int nx = x + d[0], ny = y + d[1];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if(grid[nx][ny] == '1'){
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};