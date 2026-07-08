class Solution {
public:
    const int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // 每个格子到最近的0的距离, 从0出发
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
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
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return dist;
    }
};