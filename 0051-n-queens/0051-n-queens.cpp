class Solution {
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, n);
        return ans;
    }

    void dfs(vector<string>& board, int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int c = 0 ; c < n ; c++){
            if(col[c] || diag1[row - c + n - 1] || diag2[row + c]) continue;

            board[row][c] = 'Q';
            col[c] = true;
            diag1[row - c + n - 1] = true;
            diag2[row + c] = true;
            dfs(board, row + 1, n);
            diag2[row + c] = false;
            diag1[row - c + n - 1] = false;
            col[c] = false;
            board[row][c] = '.';
        }
    }
};