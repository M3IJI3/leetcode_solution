class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int f0 = 0, f1 = 0, f2 = 0;
        for(int c : costs){
            int new_f = min(min(f0 + 9, f1 + 4), f2 + 1) + c;
            f0 = f1;
            f1 = f2;
            f2 = new_f;
        }
        return f2;
    }
};