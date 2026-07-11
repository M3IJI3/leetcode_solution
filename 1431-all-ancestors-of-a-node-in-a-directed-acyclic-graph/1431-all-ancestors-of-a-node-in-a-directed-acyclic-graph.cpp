class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // 1. 建反向图
        vector<vector<int>> graph(n);
        for(auto& e : edges){
            int u = e[0], v = e[1];
            graph[v].push_back(u);
        }
        
        vector<vector<int>> ans(n);
        
        // 2. 对每个节点BFS, 找祖先
        for(int i = 0 ; i < n ; i++){
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;

            vector<int> ancestors;
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
            sort(ancestors.begin(), ancestors.end());
            ans[i] = ancestors;
        }
        return ans;
    }
};