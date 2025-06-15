class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> st, out;
        bool res = false;
        dfs(0, pushed, st, out, popped, res);
        return res;
    }

    void dfs(int idx, vector<int>& pushed, vector<int>& st, vector<int>& out, vector<int>& popped, bool& res){
        if(res) return;
        int n = pushed.size();

        // 如果所有火车都已经入站且站台空了，记录一种出站序列
        if(idx == n && st.empty()){
            if(out == popped) res = true;
            return;
        }

        // 1) 如果站台内还有火车, 弹出栈顶元素
        if(!st.empty()){
            int x = st.back();
            st.pop_back();
            out.push_back(x);
            dfs(idx, pushed, st, out, popped, res);
            // 回溯
            st.push_back(x);
            out.pop_back();

            if(res) return; 
        }

        // 2) 如果还有火车没入栈, 可以让下一辆入站
        if(idx < n){
            st.push_back(pushed[idx]);
            dfs(idx + 1, pushed, st, out, popped, res);
            st.pop_back();
        }
    }
};