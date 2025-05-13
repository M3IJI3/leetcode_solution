class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(string& token : tokens){
            if(token != "+" && token != "-" && token != "*" && token != "/"){
                stk.push(stoi(token));
            } else {
                int top = stk.top();
                stk.pop();
                int secTop = stk.top();
                stk.pop();

                int res = 0;
                if(token == "+"){
                    res = top + secTop;
                } else if(token == "-") {
                    res = secTop - top;
                } else if(token == "*") {
                    res = secTop * top;
                } else {
                    res = secTop / top;
                }
                stk.push(res);
            }
        }
        return stk.top();
    } 
};