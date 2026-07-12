class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < n ; i++){
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                long long dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if(dist <= r1 * r1){
                    graph[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){   
            vector<bool> visited(n, false);
            ans = max(ans, dfs(graph, visited, i));
        }
        return ans;
    }

    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int idx){
        visited[idx] = true;
        int count = 1;

        for(auto& next : graph[idx]){
            if(!visited[next]){
                count += dfs(graph, visited, next);
            }
        }
        return count;
    }
};