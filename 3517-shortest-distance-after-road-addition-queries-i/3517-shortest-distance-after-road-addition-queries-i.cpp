class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < n - 1 ; i++){
            graph[i].push_back(i + 1);
        }

        vector<int> ans;
        for(auto& query : queries){
            int u = query[0], v = query[1];
            graph[u].push_back(v);

            vector<int> dist(n, -1);
            queue<int> q;
            q.push(0);
            dist[0] = 0;

            while(!q.empty()){
                auto curr = q.front(); q.pop();
                if(curr == n - 1) break;
                for(auto& next : graph[curr]){
                    if(dist[next] == -1){
                        dist[next] = dist[curr] + 1;
                        q.push(next);
                    }
                }
            }
            ans.push_back(dist[n - 1]);
        }
        return ans;
    }
};