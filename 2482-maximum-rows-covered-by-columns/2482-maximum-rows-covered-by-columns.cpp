class Solution {
public:
    int maximumRows(vector<vector<int>> &mat, int numSelect) {
        int m = mat.size(), n = mat[0].size();
        vector<int> mask(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mask[i] |= mat[i][j] << j;
            }
        }

        int ans = 0;
        for (int subset = 0; subset < (1 << n); subset++) {
            if (__builtin_popcount(subset) == numSelect) {
                int covered_rows = 0;
                for (int row : mask) {
                    if ((row & subset) == row) {
                        covered_rows++;
                    }
                }
                ans = max(ans, covered_rows);
            }
        }
        return ans;
    }
};