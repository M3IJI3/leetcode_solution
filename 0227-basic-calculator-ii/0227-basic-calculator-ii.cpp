class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        char op = '+';
        int num = 0;
        int n = s.size();

        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }

            if((!isdigit(c) && !isspace(c)) || i == n - 1){
                if(op == '+') nums.push(num);
                else if(op == '-') nums.push(-num);
                else if(op == '*'){
                    int top = nums.top(); nums.pop();
                    nums.push(top * num);
                } else if(op == '/') {
                    int top = nums.top(); nums.pop();
                    nums.push(top / num);
                }
                op = c;
                num = 0;
            }
        }

        int res = 0;
        while(!nums.empty()){
            res += nums.top();
            nums.pop();
        }

        return res;
    }
};