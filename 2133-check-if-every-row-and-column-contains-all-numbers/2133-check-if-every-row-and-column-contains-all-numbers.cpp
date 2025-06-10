class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // unordered_set<int> row[n], col[n];
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         int curr = matrix[i][j];

        //         if(row[i].count(curr) || col[j].count(curr)) return false;

        //         row[i].insert(curr);
        //         col[j].insert(curr);
        //     }
        // }
        // return true;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

         int n = matrix.size();
        for (int i = 0; i < n; i++) {
            vector<bool> row(n + 1, false); // 记录行里每个数是否出现
            vector<bool> col(n + 1, false); // 记录列里每个数是否出现
            for (int j = 0; j < n; j++) {
                int r = matrix[i][j]; // 第 i 行第 j 列
                int c = matrix[j][i]; // 第 j 行第 i 列（相当于第 i 列）

                // 如果该数在行或列里已经出现，返回 false
                if (row[r] || col[c]) return false;

                // 标记为已出现
                row[r] = col[c] = true;
            }
        }
        return true;
    }
};