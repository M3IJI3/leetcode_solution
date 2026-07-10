class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }    

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(isConnected[i][j] == 1){
                    unite(parent, i, j);
                }
            }
        }

        int province = 0;
        for(int i = 0 ; i < n ; i++){
            if(find(parent, i) == i){
                province++;
            }
        }
        return province;
    }

    int find(vector<int>& parent, int x){
        if(parent[x] != x){
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    void unite(vector<int>& parent, int x, int y){
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if(rootX != rootY){
            parent[rootX] = rootY;
        }
    }
};