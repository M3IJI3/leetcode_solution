class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        queue<int> q;
        int provinces = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                provinces++;
                q.push(i);
                visited[i] = true;
                while(!q.empty()){
                    int cur = q.front(); q.pop();
                    for(int j = 0 ; j < n ; j++){
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