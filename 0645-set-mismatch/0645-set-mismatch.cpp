class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        int count = 1;
        vector<int> temp(nums.size());
        iota(temp.begin(), temp.end(), count);

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            if(nums[i + 1] == nums[i]){
                ans.push_back(nums[i]);
            }
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(temp[i] != nums[i]){
                ans.push_back(temp[i]);
            }
        }

        return ans;
    }
};