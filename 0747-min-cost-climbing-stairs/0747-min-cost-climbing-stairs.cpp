class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f0 = 0, f1 = 0;
        for(int i = 1 ; i < cost.size() ; i++){
            int new_f = min(f1 + cost[i], f0 + cost[i - 1]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};