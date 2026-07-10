class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<bool> visited(cities, false);
        int provinces = 0;
        queue<int> q;
        for(int i = 0 ; i < cities ; i++){
            if(!visited[i]){
                provinces++;
                q.push(i);
                visited[i] = true;

                while(!q.empty()){
                    int cur = q.front(); q.pop();
                    for(int j = 0 ; j < cities ; j++){
                        if(isConnected[cur][j] == 1 && !visited[j]){
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return provinces;
    }
};