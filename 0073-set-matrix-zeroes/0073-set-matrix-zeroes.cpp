class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 0: i, j
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> rowContainZero(m, false);
        vector<bool> colContainZero(n, false);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    rowContainZero[i] = true;
                    colContainZero[j] = true;
                }
            }
        }

        for(int i = 0 ; i < m ; i++){
            if(rowContainZero[i]){
                int k = 0;
                while(k < n) matrix[i][k++] = 0;
            }
        }

        for(int j = 0 ; j < n ; j++){
            if(colContainZero[j]){
                int k = 0;
                while(k < m) matrix[k++][j] = 0;
            }
        }
    }
};