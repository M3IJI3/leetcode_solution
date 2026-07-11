class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // 1. 建图
        vector<vector<int>> graph(n);
        for(auto& inv : invocations){
            int u = inv[0], v = inv[1];
            graph[u].push_back(v);
        }

        // 2. 标记所有从 k 出发能到达的节点（可疑方法）
        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            for(auto& next : graph[curr]){
                if(!suspicious[next]){
                    suspicious[next] = true;
                    q.push(next);
                }
            }
        }

        // 3. 是否有非可疑方法调用了可疑方法
        for(auto& inv : invocations){
            auto u = inv[0], v = inv[1];
            if(!suspicious[u] && suspicious[v]){
                vector<int> ans(n);
                for(int i = 0 ; i < n ; i++) ans[i] = i;
                return ans;
            }
        }

        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(!suspicious[i]) ans.push_back(i);
        }
        return ans;
    }
};