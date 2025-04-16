/////////////
// 1st TRY //
/////////////
// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int rows = board.size();
//         int cols = board[0].size();
//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));

//         for(int i = 0 ; i < rows ; i++){
//             for(int j = 0 ; j < cols ; j++){
//                 if(dfs(board, word, visited, i, j, 0)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// private:
//     bool dfs(vector<vector<char>>& board, const string& word, 
//              vector<vector<bool>>& visited, int row, int col, int index){
//         if(index == word.size()) return true;

//         int rows = board.size();
//         int cols = board[0].size();

//         // 越界 或已访问 或当前字符串不匹配, 直接剪枝
//         if(row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || board[row][col] != word[index]){
//             return false;
//         }

//         visited[row][col] = true;

//         // 上下左右搜索
//         bool found = dfs(board, word, visited, row - 1, col, index + 1) ||
//                      dfs(board, word, visited, row + 1, col, index + 1) ||
//                      dfs(board, word, visited, row, col + 1, index + 1) ||
//                      dfs(board, word, visited, row, col - 1, index + 1);

//         visited[row][col] = false;
//         return found;
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/////////////
// 2nd TRY //
/////////////
class Solution{
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                if(dfs(board, word, visited, row, col, 0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(const vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int row, int col, int index){
        if(index == word.size()) return true;

        int rows = board.size();
        int cols = board[0].size();
        
        // 越界判断
        if(row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || board[row][col] != word[index]){
            return false;
        }

        visited[row][col] = true;

        bool found = dfs(board, word, visited, row - 1, col, index + 1) ||
                     dfs(board, word, visited, row + 1, col, index + 1) ||
                     dfs(board, word, visited, row, col - 1, index + 1) ||
                     dfs(board, word, visited, row, col + 1, index + 1);
                     
        visited[row][col] = false;
        return found;
    }
};