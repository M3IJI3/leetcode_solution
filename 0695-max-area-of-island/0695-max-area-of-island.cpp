class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int x, int y){
        int m = grid.size(), n = grid[0].size();

        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return 0;

        grid[x][y] = 0;
        return 1 + dfs(grid, x + 1, y) + dfs(grid, x - 1, y) + dfs(grid, x, y + 1) + dfs(grid, x, y - 1);
    }
};