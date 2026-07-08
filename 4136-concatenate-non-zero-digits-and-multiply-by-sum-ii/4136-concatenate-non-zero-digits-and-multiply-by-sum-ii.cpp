class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        int n = s.size();

        // 1. 前缀和
        vector<int> prefixSum(n + 1, 0);
        for(int i = 0 ; i < n ; i++){
            prefixSum[i + 1] = prefixSum[i] + (s[i] - '0');
        }

        // 2. 前缀数值 (模 MOD)
        vector<int> prefixNum(n + 1, 0);
        vector<int> nonZeroCnt(n + 1, 0);
        for(int i = 0 ; i < n ; i++){
            nonZeroCnt[i + 1] = nonZeroCnt[i] + (s[i] != '0');
            if(s[i] == '0'){
                prefixNum[i + 1] = prefixNum[i];
            } else {
                prefixNum[i + 1] = ((long long)prefixNum[i] * 10 + (s[i] - '0')) % MOD;
            }
        }

        // 3. 预计算 10 的幂次
        vector<long long> pow10(n + 1, 1);
        for(int i = 1 ; i <= n ; i++){
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<int> ans;
        for(auto& q : queries){
            int l = q[0], r = q[1];
            int sum = prefixSum[r + 1] - prefixSum[l];
            int cnt = nonZeroCnt[r + 1] - nonZeroCnt[l];
            long long x = (prefixNum[r + 1] - prefixNum[l] * pow10[cnt] % MOD + MOD) % MOD;
            ans.push_back(sum * x % MOD);
        }
        return ans;
    }
};