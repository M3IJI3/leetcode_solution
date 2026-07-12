class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for(int i = 1 ; i <= target ; i++){
            for(int x : nums){
                if(x <= i) f[i] += f[i - x];
            }
        }
        return f[target];
    }
};