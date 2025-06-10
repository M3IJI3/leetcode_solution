class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int> row[n], col[n];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int curr = matrix[i][j];

                if(row[i].count(curr) || col[j].count(curr)) return false;

                row[i].insert(curr);
                col[j].insert(curr);
            }
        }
        return true;
    }
};