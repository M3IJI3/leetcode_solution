class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> ans;
        

        for(int i = 0 ; i < nums.size() ; i++){
            window.push_back(nums[i]);

            if(window.size() == k){
                int maxWindow = INT_MIN;
                for(int num : window){
                    maxWindow = max(maxWindow, num);
                }
                ans.push_back(maxWindow);

                window.pop_front();
            }
        }
        return ans;
    }
};