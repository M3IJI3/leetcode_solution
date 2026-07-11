class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& e : edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                int v = 0;  // 节点数
                int e = 0;  // 度数和
                dfs(graph, visited, i, v, e);

                if(e == v * (v - 1)) ans++;
            }

            
        }
        return ans;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, int& v, int& e){
        visited[node] = true;
        v++;    // 当前节点的个数
        e += graph[node].size();

        for(auto& next: graph[node]){
            if(!visited[next]){
                dfs(graph, visited, next, v, e);
            }
        }
    }
};