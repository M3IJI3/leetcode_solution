class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y){
        int rootx = find(x), rooty = find(y);


        if(rootx != rooty){
            // 优化: size大的当跟 (秩和)
            if(size[rootx] < size[rooty]){
                swap(rootx, rooty);
            }    
            parent[rooty] = rootx; // 把y挂在x下面
            size[rootx] += size[rooty];
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0 ; i < n ; i++) parent[i] = i;

        for(auto& e : edges){
            unite(e[0], e[1]);
        }

        long long ans = 0;
        long long total = n;
        for(int i = 0 ; i < n ; i++){
            if(find(i) == i){
                long long setSize = size[i];
                total -= setSize;
                ans += setSize * total;
            }
        }
        return ans;
    }
};