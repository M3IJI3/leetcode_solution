class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeroCount = 0;
        int ans = 0;

        for(int right = 0 ; right < nums.size() ; right++){
            if(nums[right] == 0) zeroCount++;

            while(zeroCount > 1){
                // 收缩左边界
                if(nums[left] == 0) zeroCount--;
                left++;
            }

            ans = max(ans, right - left);
        }
        return zeroCount == 0 ? nums.size() - 1 : ans;
    }
};