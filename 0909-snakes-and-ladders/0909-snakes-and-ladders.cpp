class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false); // 标记是否访问了
        queue<pair<int, int>> q; // { 当前各自编号, 当前步数 }
        q.push({1, 0});
        visited[1] = true;

        while(!q.empty()){
            auto [curr, step] = q.front();
            q.pop();

            for(int move = 1 ; move <= 6 ; move++){
                int next = curr + move;
                if(next > n * n) break;

                auto [row, col] = getPosition(next, n);  // 拿到下一个点的坐标
                if(board[row][col] != -1){
                    next = board[row][col];
                }

                if(next == n * n) return step + 1;

                if(!visited[next]){
                    visited[next] = true;
                    q.push({next, step + 1});
                }
            }
        }
        return -1;
    }

    pair<int, int> getPosition(int num, int n){
        int r = (num - 1) / n;
        int c = (num - 1) % n;
        if(r % 2 == 1){
            c = n - 1 - c;
        }
        return { n - 1 - r, c };
    }
};