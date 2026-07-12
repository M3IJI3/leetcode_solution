class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < n ; i++){
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                long long dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if(dist <= r1 * r1){
                    graph[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(i);
            visited[i] = true;
            int explode = 1;
            while(!q.empty()){
                auto curr = q.front(); q.pop();
                for(auto& next : graph[curr]){
                    if(!visited[next]){
                        explode++;
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            ans = max(ans, explode);
        }
        return ans;
    }
};