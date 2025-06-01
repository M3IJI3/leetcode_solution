class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0); // 0=未访问, 1=访问中, 2=访问完

        // 建图
        for(auto& pre : prerequisites){
            int a = pre[0], b = pre[1];
            graph[b].push_back(a); // b->a
        }

        // 对每个点做dfs检查是否有环
        for(int i = 0 ; i < numCourses ; i++){
            if(!dfs(i, graph, visited)) return false;
        }

        return true;
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited){
        if(visited[node] == 1) return false;
        if(visited[node] == 2) return true;

        visited[node] = 1;
        for(int neighbor : graph[node]){
            if(!dfs(neighbor, graph, visited)) return false;
        }
        visited[node] = 2;
        return true;
    }
};