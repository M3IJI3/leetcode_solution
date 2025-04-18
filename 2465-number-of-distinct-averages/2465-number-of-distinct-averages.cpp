class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<double> set; 

        int left = 0, right = nums.size() - 1;
        while(left < right){
            double avg = (nums[left] + nums[right]) / 2.0;
            cout << avg << endl;
            set.insert(avg);

            left++;
            right--;
        }
        return set.size();
    }
};