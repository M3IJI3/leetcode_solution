class Solution {
public:
    int largestArea(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans = 0;
        
        // ✅ 预分配全局队列
        vector<pair<int,int>> q(m * n);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != '0' && grid[i][j] != '6'){
                    char target = grid[i][j];
                    int area = 0;
                    bool isValid = true;
                    
                    // 使用预分配的队列
                    int head = 0, tail = 0;
                    q[tail++] = {i, j};
                    grid[i][j] = '6';
                    area++;
                    
                    while(head < tail){
                        auto [x, y] = q[head++];
                        
                        for(auto& d : dirs){
                            int nx = x + d[0], ny = y + d[1];
                            
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                                isValid = false;
                                continue;
                            }
                            
                            if(grid[nx][ny] == '0'){
                                isValid = false;
                                continue;
                            }
                            
                            if(grid[nx][ny] == target){
                                grid[nx][ny] = '6';
                                area++;
                                q[tail++] = {nx, ny};
                            }
                        }
                    }
                    
                    if(isValid){
                        ans = max(ans, area);
                    }
                }
            }
        }
        return ans;
    }
};