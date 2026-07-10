class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
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
                queue<int> q;
                q.push(i);
                visited[i] = true;
                long long size = 0;
                while(!q.empty()){
                    auto curr = q.front(); q.pop();
                    size++;
                    for(auto& next : graph[curr]){
                        if(!visited[next]){
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                }
                total -= size;
                ans += total * size;
            }
        }
        return ans;
    }
};