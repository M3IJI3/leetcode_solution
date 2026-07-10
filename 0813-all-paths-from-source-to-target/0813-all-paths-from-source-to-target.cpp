class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        path.push_back(0);
        dfs(graph, 0, graph.size() - 1, path);
        return ans;
    }

    void dfs(vector<vector<int>>& graph, int curr, int target, vector<int>& path){
        if(curr == target){
            ans.push_back(path);
            return;
        }

        for(int next: graph[curr]){
            path.push_back(next);
            dfs(graph, next, target, path);
            path.pop_back();
        }
    }
};