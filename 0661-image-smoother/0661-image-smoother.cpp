class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 0));

        vector<vector<int>> directions = {
            { -1 , -1 }, { -1 , 0 }, { -1 , 1 },
            {  0 , -1 },             {  0 , 1 },
            {  1 , -1 }, {  1 , 0 }, {  1 , 1 }
        };

        // tranvers the 2d vector
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                int sum = img[row][col];
                int count = 1;

                int newRow = 0;
                int newCol = 0;

                for(auto dir : directions){
                    newRow = row + dir[0];
                    newCol = col + dir[1];

                    if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols){
                        sum += img[newRow][newCol];
                        count++;
                    }
                }

                int avg = sum / count;
                ans[row][col] = avg;
            }
        }
        return ans;
    }
};