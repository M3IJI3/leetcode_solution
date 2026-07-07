class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                
                // 每个格子贡献：顶 + 底 = 2
                ans += 2;
                
                // 四个侧面
                for(auto& d : dirs){
                    int nx = i + d[0], ny = j + d[1];
                    
                    // 如果越界，整个侧面都暴露
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n){
                        ans += grid[i][j];
                    } else {
                        // 否则只暴露高于邻居的部分
                        ans += max(0, grid[i][j] - grid[nx][ny]);
                    }
                }
            }
        }
        return ans;
    }
};