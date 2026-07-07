class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        int dirs[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<int> pools;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(land[i][j] == 0){
                    int pool = 1;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    land[i][j] = -1;

                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        for(auto& d : dirs){
                            int nx = x + d[0], ny = y + d[1];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if(land[nx][ny] == 0){
                                pool++;
                                q.push({nx, ny});
                                land[nx][ny] = -1;
                            }
                        }
                    }
                    pools.push_back(pool);
                }
            }
        }
        ranges::sort(pools);
        return pools;
    }
};

// 计算0的个数