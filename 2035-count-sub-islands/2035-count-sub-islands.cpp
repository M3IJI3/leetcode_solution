class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid2[i][j] == 1){
                    queue<pair<int, int>> q;
                    vector<pair<int, int>> cells;
                    q.push({i, j});
                    grid2[i][j] = 0;
                    bool isSub = true;

                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        if(grid1[x][y] != 1) isSub = false;
                        for(auto& d: dirs){
                            int nx = x + d[0], ny = y + d[1];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if(grid2[nx][ny] == 0) continue;
                            grid2[nx][ny] = 0;
                            q.push({nx, ny});
                        }
                    }  
                    if(isSub){
                        ans++;
                    }  
                }
            }   
        }
        return ans;
    }
};