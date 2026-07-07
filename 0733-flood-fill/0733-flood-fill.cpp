class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;

        vector<pair<int, int>> q(m * n);
        int head = 0, tail = 0;

        q[tail++] = {sr, sc};
        image[sr][sc] = color;
        while(head < tail){
            auto [x, y] = q[head++];

            for(auto& d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(image[nx][ny] == originalColor){
                    image[nx][ny] = color;
                    q[tail++] = {nx, ny};
                }
            }
        }
        return image;
    }
};