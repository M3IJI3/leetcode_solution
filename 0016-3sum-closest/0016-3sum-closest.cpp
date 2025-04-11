class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_distance = INT_MAX;
        int min_sum = 0;

        // int left = 1;
        // int right = nums.size() - 1;

        for(int i = 0 ; i < nums.size() ; i++){
            // cout << left << "," << right << endl;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int distance = abs(sum - target);
                if(distance < min_distance){
                    min_sum = sum;
                }
                right--;
            }
            left++;
        }
        return min_sum;
    }
};