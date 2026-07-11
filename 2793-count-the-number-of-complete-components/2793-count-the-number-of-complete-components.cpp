class Solution {
    vector<int> parent;
    vector<int> size;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(size[rootx] < size[rooty]) swap(rootx, rooty);
            parent[rooty] = rootx;
            size[rootx] = rooty;
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0 ; i < n ; i++) parent[i] = i; // 初始化
        for(auto& e : edges) unite(e[0], e[1]);     // 合并

        vector<int> vertexCount(n, 0);
        vector<int> edgeCount(n, 0);
        // 统计每个分量的节点数和边数
        for(int i = 0 ; i < n ; i++){
            vertexCount[find(i)]++;
        }

        for(auto& e : edges){
            edgeCount[find(e[0])]++;
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(find(i) == i){
                int v = vertexCount[i];
                int e = edgeCount[i];
                if(e == v * (v - 1) / 2) ans++;
            }
        }
        return ans;
    }
};