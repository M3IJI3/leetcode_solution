class Solution {
    vector<int> parent;

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
            parent[rooty] = rootx;
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);

        for(int i = 0 ; i < n ; i++) parent[i] = i;
        for(auto& r : roads) unite(r[0], r[1]);

        int root = find(1);
        int ans = INT_MAX;
        for(auto& r : roads){
            int u = r[0], v = r[1], d = r[2];
            if(find(u) == root){
                ans = min(ans, d);
            }
        }
        return ans;
    }
};