class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, majority = 0;

        for(int num : nums){
            if(majority == 0){
                ans = num;
            }
            majority += num == ans ? 1 : -1;
        }

        return ans;
    }
};