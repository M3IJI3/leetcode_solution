class Solution {
public:
    const int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& land) {
        // 0: 陆地   1: 水
        // 水的高度必须是0
        // 任意两个相邻的格子高度差至多为1 
        int m = land.size(), n = land[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(land[i][j] == 1){
                    q.push({i, j});
                    height[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(auto& d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(height[nx][ny] != -1) continue;
                // if(land[nx][ny] ) continue;
                height[nx][ny] = height[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return height;
    }
};

// 0 1   ->  1 0
// 0 0       2 1