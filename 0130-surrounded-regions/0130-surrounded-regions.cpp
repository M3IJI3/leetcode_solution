class Solution {
    int row, col;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        row = board.size(), col = board[0].size();
        for(int i = 0 ; i < row ; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][col - 1] == 'O') dfs(board, i, col - 1);
        }

        for(int k = 0 ; k < col ; k++){
            if(board[0][k] == 'O') dfs(board, 0, k);
            if(board[row - 1][k] == 'O') dfs(board, row - 1 , k); 
        }

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y){
        board[x][y] = '#';
        for(int i = 0 ; i < dir.size(); i++){
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && board[nx][ny] == 'O'){
                dfs(board, nx, ny);
            }
        }
    }
};