class Solution {
    int ans = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int area = 0;

                if(grid[i][j] == 1){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;

                    while(!q.empty()){
                        auto[x, y] = q.front(); q.pop();
                        area++; // 没出队一个格子, 面积 +1;
                        for(auto& d : dirs){
                            int nx = x + d[0], ny = y + d[1];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if(grid[nx][ny] == 1){
                                q.push({nx, ny});
                                grid[nx][ny] = 0;
                            }
                        }
                    }
                    ans = max(ans, area);
                }
            }
        }   
        return ans;
    }
};