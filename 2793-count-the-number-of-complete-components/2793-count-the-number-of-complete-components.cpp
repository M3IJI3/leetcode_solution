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
                queue<int> q;
                q.push(i);
                visited[i] = true;

                int v = 0, e = 0;
                while(!q.empty()){
                    auto curr = q.front(); q.pop();
                    v++;
                    e += graph[curr].size();
                    for(auto& next : graph[curr]){
                        if(visited[next]) continue;
                        q.push(next);
                        visited[next] = true;
                    }
                }
                if(e == v * (v - 1)) ans++;
            }
        }
        return ans;
    }
};