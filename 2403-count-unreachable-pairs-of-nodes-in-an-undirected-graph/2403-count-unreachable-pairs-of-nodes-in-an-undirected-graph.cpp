class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // 建立邻接表
        vector<vector<int>> graph(n);
        for(auto& e : edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        long long ans = 0;
        long long total = n;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                long long size = dfs(graph, visited, i);
                total -= size;
                ans += size * total;
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int node){
        visited[node] = true;
        int size = 1;
        for(auto& next: graph[node]){
            if(!visited[next]){
                size += dfs(graph, visited, next);
            }
        }
        return size;
    }
};