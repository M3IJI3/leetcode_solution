class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    queue<pair<int, int>> q;
                    vector<pair<int, int>> cells;
                    q.push({i, j});
                    visited[i][j] = true;
                    bool isClosed = true;

                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        cells.push_back({x, y});
                        if(x == 0 || x == m - 1 || y == 0 || y == n - 1) isClosed = false;
                        for(auto& d: dirs){
                            int nx = x + d[0], ny = y + d[1];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if(visited[nx][ny]) continue;
                            if(board[nx][ny] == 'O'){
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                    if(isClosed){
                        for(auto& [x, y] : cells){
                            board[x][y] = 'X';
                        }
                    }
                }
            }
        }
    }
};