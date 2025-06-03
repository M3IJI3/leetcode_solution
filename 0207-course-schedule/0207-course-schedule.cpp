class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);

        for(auto& pre : prerequisites){
            int a = pre[0], b = pre[1];
            graph[b].push_back(a); // b -> a;
        } 

        for(int i = 0 ; i < graph.size() ; i++){
            if(!dfs(i, graph, visited)) return false;
        }

        return true;
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited){
        if(visited[node] == 1) return false; // 回到正在访问的点 说明有环
        if(visited[node] == 2) return true; 

        visited[node] = 1;
        for(int neighbor : graph[node]){
            if(!dfs(neighbor, graph, visited)) return false;
        }
        visited[node] = 2;
        return true;
    }
};