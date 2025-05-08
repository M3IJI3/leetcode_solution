class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, majority = 0;

        for (int num : nums) {
            if (majority == 0) { // 表示当前没有候选人
                ans = num;       // 更新新的候选人
            }
            majority += ans == num ? 1 : -1; 
        }

        return ans;
    }
};