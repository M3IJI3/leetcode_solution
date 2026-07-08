class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int sx = entrance[0], sy = entrance[1];

        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == sx && j == sy) continue;
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    if(maze[i][j] == '.'){
                        q.push({i, j});
                        dist[i][j] = 0;
                    }
                }
            }
        }

        if(q.empty()) return -1;

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            if(x == sx && y == sy) return dist[x][y];
            for(auto& d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(maze[nx][ny] == '+') continue;
                if(dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return -1;
    }
};