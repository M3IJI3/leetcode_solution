class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int water = 0;

        while(left < right){
            int lower = min(height[left], height[right]);
            int currWater = lower * (right - left);
            water = max(water, currWater);
            height[left] < height[right] ? left++ : right--;
        }
        return water;
    }
};