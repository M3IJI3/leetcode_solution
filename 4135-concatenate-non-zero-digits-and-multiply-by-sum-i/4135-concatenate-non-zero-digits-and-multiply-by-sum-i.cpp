class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        int sum = 0, x = 0, i = 1;
        while(n > 0){
            int mod = n % 10;
            sum += mod;
            if(mod != 0){
                x = mod * i + x;
                i *= 10;
            }
            n /= 10;
        }
        return (long long)sum * x;
    }
};