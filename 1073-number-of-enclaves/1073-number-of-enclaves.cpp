class Solution {
    int m, n;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1){
                    dfs(grid, i, j);
                }
            }
        }

        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n) return;
        if(grid[x][y] != 1) return;

        grid[x][y] = 0;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
};