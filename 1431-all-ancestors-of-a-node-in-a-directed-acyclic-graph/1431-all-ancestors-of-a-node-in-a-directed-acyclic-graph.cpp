class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& e : edges){
            int u = e[0], v = e[1];
            graph[v].push_back(u);
        }

        vector<vector<int>> ans(n);
        for(int i = 0 ; i < n ; i++){
            vector<bool> visited(n, false);
            vector<int> ancestors;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                auto curr = q.front(); q.pop();
                for(auto& prev : graph[curr]){
                    if(!visited[prev]){
                        visited[prev] = true;
                        q.push(prev);
                        ancestors.push_back(prev);
                    }
                }
            }
            ranges::sort(ancestors);
            ans[i] = ancestors;
        }
        return ans;
    }
};