class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int mask = 0 ; mask < (1 << n) ; mask++){
            vector<int> path;
            bool valid = true;
            for(int i = 0 ; i < n ; i++){
                if(mask & (1 << i)){
                    if(!path.empty()){
                        for(int p : path){
                            if(abs(p - nums[i]) == k){
                                valid = false;
                                break;
                            }
                        }
                    }
                    path.push_back(nums[i]);
                }
                if(!valid) break;
            }
            if(valid) ans++;
        }
        return ans - 1;
    }
};