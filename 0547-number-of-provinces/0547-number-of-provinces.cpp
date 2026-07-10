class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<bool> visited(cities, false);
        int provinces = 0;
        for(int i = 0 ; i < cities ; i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                provinces++;
            }
        }
        return provinces;
    }

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        visited[i] = true;
        for(int j = 0 ; j < isConnected.size() ; j++){
            if(isConnected[i][j] == 1 && !visited[j]){
                dfs(isConnected, visited, j);
            }
        }
    }
};