class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        
        vector<vector<int>> graph(n);
        for(auto& con : connections){
            int u = con[0], v = con[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }      

        vector<bool> visited(n, false);
        int components = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(graph, visited, i);
                components++;
            }
        }
        return components - 1;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int i){
        visited[i] = true;
        for(auto& next : graph[i]){
            if(!visited[next]){
                visited[next] = true;
                dfs(graph, visited, next);
            }
        }
    }
};