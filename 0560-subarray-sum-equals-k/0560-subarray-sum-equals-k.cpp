class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt = {{0, 1}};
        int s = 0, ans = 0;
        for(int x : nums){ 
            s += x;
            ans += cnt[s - k];
            cnt[s]++;
        }
        return ans;
    }
};

// 0 1 2 3 