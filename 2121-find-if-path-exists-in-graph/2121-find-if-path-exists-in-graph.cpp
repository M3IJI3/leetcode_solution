class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto& e: edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int curr = q.front(); q.pop();
            if(curr == destination) return true;
            for(int next : graph[curr]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        return false;
    }
};