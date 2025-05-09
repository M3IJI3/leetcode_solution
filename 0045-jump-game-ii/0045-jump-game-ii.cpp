class Solution {
public:
    int jump(vector<int>& nums) {
        int currEnd = 0; // 表示当前可到达最远距离
        int nextEnd = 0; // 表示下一跳可到达最远距离
        int jump = 0;

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            nextEnd = max(nextEnd, i + nums[i]);

            if(i == currEnd) { // 表示抵达当前最远位置
                jump++;
                currEnd = nextEnd; // 更新当前可到达最远位置

                if(currEnd >= nums.size() - 1) break;
            }
        }
        return jump;
    }
};