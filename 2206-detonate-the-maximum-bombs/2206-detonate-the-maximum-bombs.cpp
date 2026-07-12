class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            vector<bool> visited(n, false);
            queue<tuple<int, int, int>> q;
            int x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
            q.push({x, y, r});
            visited[i] = true;
            int explode = 1;
            
            while(!q.empty()){
                auto [cx, cy, cr] = q.front(); q.pop();  // 解包当前炸弹
                for(int j = 0 ; j < n ; j++){
                    if(!visited[j]){
                        long long nx = bombs[j][0], ny = bombs[j][1];
                        long long dist = (nx-cx)*(nx-cx) + (ny-cy)*(ny-cy);
                        if(dist <= (long long)cr * cr){  // 用当前炸弹的半径
                            explode++;
                            q.push({bombs[j][0], bombs[j][1], bombs[j][2]});
                            visited[j] = true;
                        }
                    }
                }
            }
            ans = max(ans, explode);
        }
        return ans;
    }
};