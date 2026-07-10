class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        for(int i = 0 ; i < n ; i++) parent[i] = i;

        for(auto& e : edges){
            unite(parent, e[0], e[1]);
        }

        return find(parent, source) == find(parent, destination);
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