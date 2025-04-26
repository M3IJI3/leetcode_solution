class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, n = height.size();
        int left = 0, right = n - 1;

        while(left < right){
            int lower = min(height[left], height[right]);
            area = max(area, lower * (right - left));
            height[left] < height[right] ? left++ : right--;
        }

        return area;
    }
};