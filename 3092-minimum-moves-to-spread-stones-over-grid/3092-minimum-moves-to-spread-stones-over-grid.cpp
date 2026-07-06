class Solution {
    int ans = INT_MAX;
    vector<pair<int, int>> from, to;
    vector<bool> used;
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                    to.push_back({i, j});
                } else if(grid[i][j] > 1){
                    for(int k = 0 ; k < grid[i][j] - 1 ; k++){
                        from.push_back({i, j});
                    }
                }
            }
        }

        used = vector<bool>(n, false);
        vector<pair<int, int>> path;
        dfs(0, path);
        return ans;
    }

    void dfs(int index, vector<pair<int, int>>& path){
        if(index == from.size()){
            int total = 0;
            for(int i = 0 ; i < path.size() ; i++){
                total += abs(path[i].first - to[i].first) + abs(path[i].second - to[i].second);
            }
            ans = min(ans, total);
            return;
        }

        for(int i = 0 ; i < from.size() ; i++){
            if(used[i]) continue;
            used[i] = true;
            path.push_back(from[i]);
            dfs(index + 1, path);
            path.pop_back();
            used[i] = false;
        }
    }
};