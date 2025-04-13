class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        backtrack(n, 0, 0, path, result);
        return result;
    }

private:
    void backtrack(int n, int left, int right, string& path, vector<string>& result){
        // 终止条件: 左右括号都用完
        if(left == n && right == n){
            result.push_back(path);
            return;
        }

        // 剪枝: 加左括号(只要还没到n就能加)
        if(left < n){
            path.push_back('(');
            backtrack(n, left + 1, right, path, result);
            path.pop_back();
        }

        // 剪枝: 加右括号(右括号的数量不能超过左括号)
        if(right < left){
            path.push_back(')');
            backtrack(n, left, right + 1, path, result);
            path.pop_back();
        }
    }
};