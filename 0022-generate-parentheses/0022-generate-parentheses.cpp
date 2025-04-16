/////////////
// 1st TRY //
/////////////
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> result;
//         string path;
//         backtrack(n, 0, 0, path, result);
//         return result;
//     }

// private:
//     void backtrack(int n, int left, int right, string& path, vector<string>& result){
//         // 终止条件: 左右括号都用完
//         if(left == n && right == n){
//             result.push_back(path);
//             return;
//         }

//         // 剪枝: 加左括号(只要还没到n就能加)
//         if(left < n){
//             path.push_back('(');
//             backtrack(n, left + 1, right, path, result);
//             path.pop_back();
//         }

//         // 剪枝: 加右括号(右括号的数量不能超过左括号)
//         if(right < left){
//             path.push_back(')');
//             backtrack(n, left, right + 1, path, result);
//             path.pop_back();
//         }
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/////////////
// 2nd TRY //
/////////////
class Solution{
public:
    vector<string> generateParenthesis(int n) { 
        vector<string> ans;
        string path;
        backtrack(ans, path, n, 0, 0);
        return ans;
    }
private:
    void backtrack(vector<string>& ans, string& path, int n, int left, int right){
        if(path.size() == 2 * n){ // left == n && right == n
            ans.push_back(path);
            return;
        }

        // 左括号的数量要小于n
        if(left < n){
            path.push_back('(');
            backtrack(ans, path, n, left + 1, right);
            path.pop_back();
        }

        // 右括号的数量小于左括号的数量
        if(right < left){
            path.push_back(')');
            backtrack(ans, path, n, left, right + 1);
            path.pop_back();
        }
    }
};
/**
level0:                   "" (left=0, right=0)
                        /       
level1:               "(" (1,0)
                    /       \
level2:         "((" (2,0)    "()"(1,1)
               /     \            \
level3:   "(((" (3,0) "(()" (2,1)  "()" → 不合法(1,2) ❌
             |        \            (剪枝)
level4:   "((()" (3,1) "(()("(3,1) 
           /            \    
level5: "((())" (3,2)   "(()()" (3,2)
         |                 |
level6: "((()))" (3,3)     "(()())" (3,3)
  
                (← 回到“(()”)
                /     
          "(())" (2,2)
            \
         "(())(" (3,2)
            |
         "(())()" (3,3)

        (← 回到“()”)
           \
         "()(" (2,1)
          /    \
     "()((" (3,1) "()()" (2,2

*/