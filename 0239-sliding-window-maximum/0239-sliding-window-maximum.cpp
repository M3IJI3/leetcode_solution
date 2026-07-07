class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<int> ans(n - k + 1);
        deque<int> d;
        for(int r = 0 ; r < nums.size() ; r++){
            while(!d.empty() && nums[d.back()] <= nums[r]){
                d.pop_back();
            }

            d.push_back(r);

            int l = r - k + 1;
            if(l < 0) continue;

            if(d.front() < l){
                d.pop_front();
            }
            ans[l] = nums[d.front()];
        }
        return ans;
    }
};