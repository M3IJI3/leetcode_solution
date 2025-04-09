class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int perimeter = 0;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                // if it's land
                if(grid[i][j] == 1){
                    perimeter += 4;

                    // if there is land topside
                    if(i > 0 && grid[i - 1][j] == 1){
                        perimeter -= 2; // both lands share same edges
                    }

                    // if there is land leftside
                    if(j > 0 && grid[i][j - 1] == 1){
                        perimeter -= 2;
                    }

                }
            }
        }
        return perimeter;
    }
};