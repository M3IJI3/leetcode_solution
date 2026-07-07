class Solution {
    int m, n;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
public:
    int largestArea(vector<string>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        
        int ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != '0' && grid[i][j] != '6'){
                    int area = 0;
                    bool isValid = true;
                    
                    dfs(grid, i, j, grid[i][j], area, isValid);
                    
                    if(isValid){
                        ans = max(ans, area);
                    }
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<string>& grid, int x, int y, char target, int& area, bool& isValid){
        if(x < 0 || x >= m || y < 0 || y >= n){
            isValid = false;
            return;
        }
        
        if(grid[x][y] == '0'){
            isValid = false;
            return;
        }
        
        if(grid[x][y] != target) return;
        
        grid[x][y] = '6';
        area++;
        
        dfs(grid, x+1, y, target, area, isValid);
        dfs(grid, x-1, y, target, area, isValid);
        dfs(grid, x, y+1, target, area, isValid);
        dfs(grid, x, y-1, target, area, isValid);
    }
};