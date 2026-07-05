class Solution {
    int ans = INT_MAX;
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        dfs(strength, 0, k, 0);
        return ans;
    }

    void dfs(vector<int>& strength, int opened, int k, int time){
        if(opened == strength.size()){
            ans = min(ans, time);
            return;
        }

        if(time >= ans) return;
        int x = 1 + k * opened;

        for(int i = 0 ; i < strength.size() ; i++){
            if(strength[i] < 0) continue;
            int needTime = (strength[i] + x - 1) / x;
            strength[i] = -strength[i];
            dfs(strength, opened + 1, k, time + needTime);
            strength[i] = -strength[i];
        }
    }
};