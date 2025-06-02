class Solution {
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0) return 0;
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
        int answer = 0;
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                if(grid[row][col] == '1' && !visited[row][col]){
                    bfs(grid, row, col, visited);
                    answer++;
                }
            }
        }
        return answer;
    }

    // 对每个点进行bfs
    void bfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        while(!q.empty()){
            pair<int, int> tmp = q.front();
            q.pop();
            for(int i = 0 ; i < dir.size() ; i++){
                int tmp_row = tmp.first + dir[i][0];
                int tmp_col = tmp.second + dir[i][1];
                if(tmp_row >= 0 && tmp_row < grid.size() && tmp_col >= 0 && tmp_col < grid[0].size() && 
                    !visited[tmp_row][tmp_col] && grid[tmp_row][tmp_col] == '1'){
                    q.push({tmp_row, tmp_col});
                    visited[tmp_row][tmp_col] = true;
                }
            }
        }
    }
};