class Solution {
public:
    const int MOD = 1e9+7;
    int countTexts(string pressedKeys) { 
        int n = pressedKeys.size();
        vector<long long> f(max(n, 4) + 1, 0);
        vector<long long> g(max(n, 4) + 1, 0);
        f[0] = g[0] = 1;
        f[1] = g[1] = 1;
        f[2] = g[2] = 2;
        f[3] = g[3] = 4;

        for(int i = 4 ; i <= n ; i++){
            f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
            g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD;
        }

        long long ans = 1;
        for(int i = 0 ; i < n;){
            int j = i;
            while(j < n && pressedKeys[i] == pressedKeys[j]){
                j++;
            }
            int len = j - i;

            if(pressedKeys[i] == '7' || pressedKeys[i] == '9'){
                ans = (ans * g[len]) % MOD; 
            } else {
                ans = (ans * f[len]) % MOD;
            }
            i = j;
        }
        return ans;
    }
};