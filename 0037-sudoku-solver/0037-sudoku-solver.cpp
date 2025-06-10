// 稍微复杂
// class Solution {
//     int rows = 9, cols = 9;
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }
// private:
//     bool isRowLegal(vector<vector<char>>& board, int row, int num){
//         for(int i = 0 ; i < rows ; i++){
//             if(board[row][i] == num + '0') return false;
//         }
//         return true;
//     }

//     bool isColLegal(vector<vector<char>>& board, int col, int num){
//         for(int i = 0 ; i < cols ; i++){
//             if(board[i][col] == num + '0') return false;
//         }
//         return true;
//     }

//     bool isBlockLegal(vector<vector<char>>& board, int row, int col, int num){
//         int startRow = row / 3 * 3;
//         int startCol = col / 3 * 3;
//         for(int i = startRow ; i < startRow + 3 ; i++){
//             for(int j = startCol ; j < startCol + 3 ; j++){
//                 if(board[i][j] == num + '0') return false;
//             }
//         }
//         return true;
//     }

//     bool solve(vector<vector<char>>& board){
//         for(int row = 0 ; row < rows ; row++){
//             for(int col = 0 ; col < cols ; col++){
//                 if(board[row][col] == '.'){
//                     for(int num = 1 ; num <= 9 ; num++){
//                         if(isRowLegal(board, row, num) && 
//                            isColLegal(board, col, num) && 
//                            isBlockLegal(board, row, col, num)){

//                             board[row][col] = num + '0';
//                             if(solve(board)) return true;
//                             board[row][col] = '.';
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }

    bool dfs(vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c <= '9' ; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;
                            if(dfs(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0 ; i < 9 ; i++){
            if(board[row][i] == c) return false;
            if(board[i][col] == c) return false;
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == c) return false;
        }
        return true;
    }
};




