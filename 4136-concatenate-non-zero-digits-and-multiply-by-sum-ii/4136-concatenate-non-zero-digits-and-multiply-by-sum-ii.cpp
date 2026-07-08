class Solution {
public:
    // “边算边取模”和“算完再取模”结果一样
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        int n = s.size();

        // 1. 计算前缀和;
        vector<int> preSum(n + 1, 0);
        for(int i = 0 ; i < n; i++){
            preSum[i + 1] = preSum[i] + (s[i] - '0');
        }

        // 2. 计算前缀数 (模 MOD)
        vector<int> preNum(n + 1, 0);
        vector<int> nonZeroCnt(n + 1, 0);
        for(int i = 0 ; i < n ; i++){
            nonZeroCnt[i + 1] = nonZeroCnt[i] + (s[i] != '0');
            if(s[i] == '0'){
                preNum[i + 1] = preNum[i];
            } else {
                preNum[i + 1] = ((long long)preNum[i] * 10 + (s[i] - '0')) % MOD;
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
            int sum = preSum[r + 1] - preSum[l];
            int cnt = nonZeroCnt[r + 1] - nonZeroCnt[l];
            long long x = (preNum[r + 1] - preNum[l] * pow10[cnt] % MOD + MOD) % MOD;
            ans.push_back(sum * x % MOD);
        }
        return ans;
    }
};