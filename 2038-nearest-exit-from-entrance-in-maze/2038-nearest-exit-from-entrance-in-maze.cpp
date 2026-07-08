class Solution {
public:
    const int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int sx = entrance[0], sy = entrance[1];
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({sx, sy});
        dist[sx][sy] = 0;

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            if((x == 0 || x == m - 1 || y == 0 || y == n - 1) && !(x == sx && y == sy)) return dist[x][y];
            
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