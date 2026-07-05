class Solution {
    const int MOD = 1e9+7;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector max_sum(n + 1, vector<int>(n + 1, INT_MIN));
        vector ways(n + 1, vector<int>(n + 1));
        max_sum[0][0] = 0;
        ways[0][0] = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                char ch = board[i][j];
                if(ch == 'X') continue;

                max_sum[i + 1][j + 1] = max({max_sum[i][j], max_sum[i][j + 1], max_sum[i + 1][j]});
                int s = max_sum[i + 1][j + 1];
                long long w = 0;

                if(max_sum[i][j] == s){
                    w += ways[i][j];
                }
                if(max_sum[i][j + 1] == s){
                    w += ways[i][j + 1];
                }
                if(max_sum[i + 1][j] == s){
                    w += ways[i + 1][j];
                }
                ways[i + 1][j + 1] = w % MOD;
                if('1' <= ch && ch <= '9') {
                    max_sum[i + 1][j + 1] += ch - '0';
                }
            }
        }
        return max_sum[n][n] < 0 ? vector{0, 0} : vector{max_sum[n][n], ways[n][n]};
    }
};