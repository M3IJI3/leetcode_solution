// 皇后肯定不在同一行 所以每一行只放一个棋子
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> col(n, false);          // 当前列是否有皇后
        vector<bool> diag(2 * n - 1, false); // 主对角线是否有皇后
        vector<bool> anti(2 * n - 1, false); // 副对角线是否有皇后
        backtrack(0, n, col, diag, anti, count);
        return count;  
    }
private:
    void backtrack(int row, int n, vector<bool>& col, vector<bool>& diag, vector<bool>& anti, int& count){
        if(row == n){
            count++;
            return;
        }

        for(int j = 0 ; j < n ; j++){
            int d = row - j + n - 1; // 主对角线索引
            int a = row + j;         // 副对角线索引

            if(col[j] || diag[d] || anti[a]) continue;

            col[j] = diag[d] = anti[a] = true;
            backtrack(row + 1, n, col, diag, anti, count);
            col[j] = diag[d] = anti[a] = false;
        }
    }
};