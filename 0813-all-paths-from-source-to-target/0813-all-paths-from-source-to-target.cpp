class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});
        while(!q.empty()){
            auto [curr, path] = q.front(); q.pop();
            if(curr == target){
                ans.push_back(path);
                continue;
            }

            for(int next: graph[curr]){
                vector<int> newPath = path;
                newPath.push_back(next);
                q.push({next, newPath});
            }
        }
        return ans;
    }
};