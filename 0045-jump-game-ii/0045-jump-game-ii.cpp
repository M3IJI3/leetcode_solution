class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0; 
        int end = 0;      // 当前能跳到最远的位置 
        int farthest = 0; // 下一跳跳到最远的位置

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            farthest = max(farthest, i + nums[i]);

            if(i == end){
                jump++;
                end = farthest;

                if(end >= nums.size() - 1) break;
            }
        }
        return jump;
    }
};