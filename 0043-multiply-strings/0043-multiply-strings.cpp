class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);

        for(int i = m - 1 ; i >= 0 ; i--){
            for(int j = n - 1 ; j >= 0 ; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1; // p1 高位, p2 低位

                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }

        string answer;
        int i = 0;
        while(i < res.size() && res[i] == 0) i++; // 跳过一开始前面的0
        while(i < res.size()){
            answer += res[i] + '0';
            i++;
        }

        return answer;
    }
};