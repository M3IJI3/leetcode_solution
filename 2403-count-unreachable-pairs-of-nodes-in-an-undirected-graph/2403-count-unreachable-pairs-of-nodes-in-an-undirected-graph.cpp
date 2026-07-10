class Solution {
public:
    // 并查集核心数据结构
    vector<int> parent;
    vector<int> size;  // 记录每个集合的大小
    
    // 查找根节点（带路径压缩）
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 路径压缩
        }
        return parent[x];
    }
    
    // 合并两个节点所在的集合
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;  // 已经在同一集合
        
        // 优化：小集合合并到大集合
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        // 1. 初始化并查集
        parent.resize(n);
        size.resize(n, 1);  // 每个集合初始大小为 1
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // 2. 合并所有边
        for (auto& edge : edges) {
            unite(edge[0], edge[1]);
        }
        
        // 3. 统计答案
        long long total = n;
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            // 只处理每个集合的根节点
            if (find(i) == i) {
                long long setSize = size[i];
                total -= setSize;
                ans += setSize * total;
            }
        }
        
        return ans;
    }
};