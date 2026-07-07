class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string s = to_string(n);
        string xstr = "";
        int sum = 0;
        for(char c : s){
            if(c == '0') continue;
            xstr.push_back(c);
            sum += (c - '0');
        }
        long long x = stoll(xstr);
        return x * sum;
    }
};