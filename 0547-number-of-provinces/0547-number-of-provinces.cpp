class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);

        // 初始化
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }

        // 合并
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
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

    void unite(vector<int>& parent, int x, int y){
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if(rootX != rootY){
            parent[rootY] = rootX;
        }
    }
    
    int find(vector<int>& parent, int x){
        if(parent[x] != x){
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};