class Solution {
    int n;
    int maxDist;
    const int INF = INT_MAX / 2;
    vector<vector<int>> g;      // 原始邻接矩阵
    vector<bool> keep;          // 保留/关闭状态
    int ans = 0;
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        this->n = n;
        this->maxDist = maxDistance;

        g = vector<vector<int>>(n, vector<int>(n, INF));
        for(int i = 0 ; i < n ; i++) g[i][i] = 0; // 自己到自己是0

        for(auto& r : roads){
            int u = r[0], v = r[1], w = r[2];
            g[u][v] = min(g[u][v], w);
            g[v][u] = min(g[v][u], w);
        }

        keep = vector<bool>(n, false);
        dfs(0);
        return ans;
    }

    void dfs(int index){
        if(index == n){
            if(check()) ans++;
            return;
        }

        keep[index] = false;
        dfs(index + 1);

        keep[index] = true;
        dfs(index + 1);
    }

    bool check(){
        vector<vector<int>> dist = g;

        // Floyd 最短路算法
        for(int i = 0 ; i < n ; i++){
            if(!keep[i]) continue;
            for(int j = 0 ; j < n ; j++){
                if(!keep[j]) continue;
                for(int k = 0 ; k < n ; k++){
                    if(!keep[k]) continue;
                    if(dist[j][i] + dist[i][k] < dist[j][k]){
                        dist[j][k] = dist[j][i] + dist[i][k];
                    }
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(!keep[i]) continue;
            for(int j = 0 ; j < n ; j++){
                if(!keep[j]) continue;
                if(dist[i][j] > maxDist){
                    return false;
                }
            }
        }
        return true;
    }
};