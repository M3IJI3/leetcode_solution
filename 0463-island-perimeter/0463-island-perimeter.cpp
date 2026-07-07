class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    int perimeter = 0;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = -1;

                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        for(auto& d : dirs){
                            int nx = x + d[0], ny = y + d[1];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                                perimeter++;
                                continue;
                            }

                            if(grid[nx][ny] == 0){
                                perimeter++;
                                continue;
                            }

                            if(grid[nx][ny] == -1) continue;

                            if(grid[nx][ny] == 1){
                                q.push({nx, ny});
                                grid[nx][ny] = -1;
                            } 
                        }
                    }
                    ans += perimeter;
                }
            }
        }
        return ans;
    }
};