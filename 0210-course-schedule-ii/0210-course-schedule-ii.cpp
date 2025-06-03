class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. 建图
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);

        for(auto& pre : prerequisites){
            int a = pre[0], b = pre[1]; 
            graph[b].push_back(a); // 表示 b -> a, 上完b就可以去a
        }

        // 2. dfs
        vector<int> res;
        for(int i = 0 ; i < graph.size() ; i++){
            if(!dfs(i,graph, visited, res)) return {};
        }   
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& res){
        if(visited[node] == 1) return false; // 出现环
        if(visited[node] == 2) return true;  // 已完成, 不再处理

        visited[node] = 1;
        for(auto& neighbor : graph[node]){
            if(!dfs(neighbor,graph,visited,res)) return false;
        }
        visited[node] = 2;
        res.push_back(node);
        return true;
    }
};