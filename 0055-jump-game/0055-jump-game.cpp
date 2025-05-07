class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        // 在所能及范围内遍历
        for(int i = 0 ; i <= maxReach ; i++){
            maxReach = max(maxReach, i + nums[i]); // 更新最远可以跳到的位置
            if(maxReach >= nums.size() - 1) return true;
        }

        return false;
    }
};