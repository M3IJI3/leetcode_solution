class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(auto& d: dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(image[nx][ny] == originalColor){
                    q.push({nx, ny});
                    image[nx][ny] = color;
                }
            }
        }
        return image;
    }
};