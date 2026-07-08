class Solution {
public:
    const int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        queue<pair<int, int>> q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(land[i][j] == 1){
                    q.push({i, j});
                    land[i][j] = 0;
                } else {
                    land[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(auto& d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(land[nx][ny] != -1) continue;
                land[nx][ny] = land[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return land;
    }
};