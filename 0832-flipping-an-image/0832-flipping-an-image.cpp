class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0 ; i < image.size() ; i++){
            flipVector(image[i]);
            invertVector(image[i]);
        }
        return image;
    }
private:
    void flipVector(vector<int>& v){
        int left = 0, right = v.size() - 1;

        while(left < right){
            int temp = v[left];
            v[left] = v[right];
            v[right] = temp;

            left++;
            right--;
        }
    }

    void invertVector(vector<int>& v){
        for(int i = 0 ; i < v.size() ; i++){
            v[i] ^= 1;
        }
    }
};