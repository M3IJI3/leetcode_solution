class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if(n == 0) return res;

        int start = 0;
        for(int i = 0 ; i < n ; i++){
            if(i + 1 < n && nums[i] + 1 == nums[i + 1]) continue;

            if(start == i){
                res.push_back(to_string(nums[start]));
            } else {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            }
            start = i + 1;
            // cout << i << "," << start << endl;
        } 
        return res;
    }
};