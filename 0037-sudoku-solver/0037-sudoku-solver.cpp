class Solution {
    int rows = 9, cols = 9;
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
private:
    bool isRowLegal(vector<vector<char>>& board, int row, int num){
        for(int i = 0 ; i < rows ; i++){
            if(board[row][i] == num + '0') return false;
        }
        return true;
    }

    bool isColLegal(vector<vector<char>>& board, int col, int num){
        for(int i = 0 ; i < cols ; i++){
            if(board[i][col] == num + '0') return false;
        }
        return true;
    }

    bool isBlockLegal(vector<vector<char>>& board, int row, int col, int num){
        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;
        for(int i = startRow ; i < startRow + 3 ; i++){
            for(int j = startCol ; j < startCol + 3 ; j++){
                if(board[i][j] == num + '0') return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                if(board[row][col] == '.'){
                    for(int num = 1 ; num <= 9 ; num++){
                        if(isRowLegal(board, row, num) && 
                           isColLegal(board, col, num) && 
                           isBlockLegal(board, row, col, num)){

                            board[row][col] = num + '0';
                            if(solve(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};




