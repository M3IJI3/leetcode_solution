class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto& e : edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return dfs(graph, visited, source, destination);
    }

    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int destination){
        if(curr == destination) return true;
        visited[curr] = true;

        for(int next : graph[curr]){
            if(!visited[next]){
                if(dfs(graph, visited, next, destination)) return true;
            }
        }
        return false;
    }
};