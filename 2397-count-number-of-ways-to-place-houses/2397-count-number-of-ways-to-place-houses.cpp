class Solution {
public:
    const int MOD = 1e9+7;
    int countHousePlacements(int n) {
        if(n == 1) return 4;
        if(n == 2) return 9;

        long long f0 = 1, f1 = 2;
        for(int i = 2 ; i <= n ; i++){
            int new_f = (f0 + f1) % MOD;
            f0 = f1;
            f1 = new_f;
        }
        return (f1 * f1) % MOD;
    }
};