class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // int rows = img.size();
        // int cols = img[0].size();
        // vector<vector<int>> ans(rows, vector<int>(cols, 0));

        // vector<vector<int>> directions = {
        //     { -1 , -1 }, { -1 , 0 }, { -1 , 1 },
        //     {  0 , -1 },             {  0 , 1 },
        //     {  1 , -1 }, {  1 , 0 }, {  1 , 1 }
        // };

        // // tranvers the 2d vector
        // for(int row = 0 ; row < rows ; row++){
        //     for(int col = 0 ; col < cols ; col++){
        //         int sum = img[row][col];
        //         int count = 1;

        //         int newRow = 0;
        //         int newCol = 0;

        //         for(auto dir : directions){
        //             newRow = row + dir[0];
        //             newCol = col + dir[1];

        //             if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols){
        //                 sum += img[newRow][newCol];
        //                 count++;
        //             }
        //         }

        //         int avg = sum / count;
        //         ans[row][col] = avg;
        //     }
        // }
        // return ans;
        ///////////////////////////////////////////////////////////////

        int rows = img.size();
        int cols = img[0].size();

        // Apply the average function to each pixel in the image matrix
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                result[r][c] = calculateAverage(img, r, c, rows, cols);
            }
        }

        return result;

    }
private:
    int calculateAverage(const vector<vector<int>>& img, int r, int c, int rows, int cols) {
        int total = 0;
        int count = 0;

        // Define the boundaries for the neighboring pixels
        int top = max(0, r - 1);
        int bottom = min(rows, r + 2);
        int left = max(0, c - 1);
        int right = min(cols, c + 2);

        // Iterate over the neighboring pixels and calculate the sum and count
        for (int row = top; row < bottom; row++) {
            for (int col = left; col < right; col++) {
                total += img[row][col];
                count += 1;
            }
        }

        // Calculate and return the average value for the pixel
        return total / count;
    }
};