class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<bool>> pacific(m, vector<bool>(n, false)); 
        vector<vector<bool>> atlantic(m, vector<bool>(n, false)); 

        queue<pair<int, int>> q;

        // 太平洋: 上边界和左边界
        for(int i = 0 ; i < m ; i++){
            q.push({i, 0});
            pacific[i][0] = true;
        }
        for(int j = 0 ; j < n ; j++){
            q.push({0, j});
            pacific[0][j] = true;
        }
        bfs(heights, q, pacific);

        // 大西洋: 下边界和右边界
        for(int i = 0 ; i < m ; i++){
            q.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }
        for(int j = 0 ; j < n ; j++){
            q.push({m - 1, j});
            atlantic[m - 1][j] = true;
        }
        bfs(heights, q, atlantic);

        vector<vector<int>> ans;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited){
        int m = heights.size(), n = heights[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(auto& d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(visited[nx][ny]) continue;
                if(heights[nx][ny] >= heights[x][y]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
};