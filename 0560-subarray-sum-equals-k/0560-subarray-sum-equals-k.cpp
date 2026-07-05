class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0 ; i < n ; i++){
            presum[i + 1] = presum[i] + nums[i];
        }

        int ans = 0;
        unordered_map<int, int> cnt;
        for(int x: presum){
            if(cnt.count(x - k)){
                ans += cnt[x - k];
            }
            cnt[x]++;
        }
        return ans;
    }
};

// 0 1 2 3 