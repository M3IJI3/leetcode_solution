class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // 1. 建反向图
        vector<vector<int>> graph(n);
        for(auto& e: edges){
            int u = e[0], v = e[1];
            graph[v].push_back(u);
        }

        vector<vector<int>> ans(n);

        for(int i = 0 ; i < n ; i++){
            vector<bool> visited(n, false);
            vector<int> path;
            dfs(graph, path, visited, i);
            ranges::sort(path);
            ans[i] = path;
        }
        return ans;
        
    }

    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int curr){
        visited[curr] = true;
        for(auto& prev : graph[curr]){
            if(!visited[prev]){
                path.push_back(prev);
                dfs(graph, path, visited, prev);
            }
        }
    }
};