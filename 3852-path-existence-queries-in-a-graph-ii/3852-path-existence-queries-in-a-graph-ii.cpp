class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> idx(n);
        ranges::iota(idx, 0);
        ranges::sort(idx, {}, [&](int i) { return nums[i]; });

        // rank[i] 表示 nums[i] 是 nums 中的第几小，或者说节点 i 在 idx 中的下标
        vector<int> rank(n);
        for (int i = 0; i < n; i++) {
            rank[idx[i]] = i;
        }

        // 双指针，从第 i 小的数开始，向左一步，最远能跳到第 left 小的数
        int mx = bit_width((uint32_t) n);
        vector pa(n, vector<int>(mx)); // 更快的写法见另一份代码【C++ array】
        int left = 0;
        for (int i = 0; i < n; i++) {
            while (nums[idx[i]] - nums[idx[left]] > maxDiff) {
                left++;
            }
            pa[i][0] = left;
        }

        // 倍增
        for (int i = 0; i < mx - 1; i++) {
            for (int x = 0; x < n; x++) {
                int p = pa[x][i];
                pa[x][i + 1] = pa[p][i];
            }
        }

        vector<int> ans(queries.size());
        for (int qi = 0; qi < queries.size(); qi++) {
            int l = queries[qi][0], r = queries[qi][1];
            if (l == r) { // 不用跳
                continue;
            }
            l = rank[l];
            r = rank[r];
            if (l > r) { // 保证 l 在 r 左边
                swap(l, r);
            }
            // 从 r 开始，向左跳到 l
            int res = 0;
            for (int k = mx - 1; k >= 0; k--) {
                if (pa[r][k] > l) {
                    res |= 1 << k;
                    r = pa[r][k];
                }
            }
            ans[qi] = pa[r][0] > l ? -1 : res + 1; // 再跳一步就能到 l
        }
        return ans;
    }
};
