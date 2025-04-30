class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, maxLen = 0;

        for(int right = 0 ; right < nums.size() ; right++){
            // 维护 maxDeque: 从大到小
            while(!maxDeque.empty() && nums[right] > maxDeque.back()){
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);

            // 维护 minDeque: 从小到大
            while(!minDeque.empty() && nums[right] < minDeque.back()){
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);

            // 检查当前窗口是否合法
            while(maxDeque.front() - minDeque.front() > limit){
                // 收缩左边界
                if(nums[left] == maxDeque.front()) maxDeque.pop_front();
                if(nums[left] == minDeque.front()) minDeque.pop_front();
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};