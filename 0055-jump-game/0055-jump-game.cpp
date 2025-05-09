class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 记录当前最远可以跳跃的位置
        int maxReach = 0;

        // 遍历当前位置到最远位置的元素
        for(int i = 0 ; i <= maxReach ; i++){ // -> 对于每一个索引 i 都要更新最远可以跳到的位置
            // 判断 maxReach 是否抵达终点
            if(maxReach >= nums.size() - 1) return true;
            // 更新最远可以跳到的位置
            maxReach = max(maxReach, i + nums[i]);
        }
        return false;
    }
};