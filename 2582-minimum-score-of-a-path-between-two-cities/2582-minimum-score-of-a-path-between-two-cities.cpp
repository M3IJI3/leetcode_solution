class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto& r : roads){
            int u = r[0], v = r[1], d = r[1];
            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }

        vector<bool> visited(n + 1, false);
        dfs(graph, visited, 1);

        int ans = INT_MAX;
        for(auto& r : roads){
            int u = r[0], v = r[1], d = r[2];
            if(visited[u] && visited[v]){
                ans = min(ans, d);
            }
        }
        return ans;
    }

    void dfs(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int node){
        visited[node] = true;
        for(auto& [next, dist] : graph[node]){
            if(!visited[next]){
                dfs(graph, visited, next);
            }
        }
    }
};