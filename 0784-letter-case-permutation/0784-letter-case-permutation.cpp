class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string path;
        backtrack(result, s, path, 0);
        return result;
    }
private:
    void backtrack(vector<string>& result, string& s, string& path, int index){
        // 这题是一个位置做一个决策
        // for循环会导致每一层从头开始选
        if(s.size() == index){
            result.push_back(path);
            return;
        }

        // 处理当前字符
        if(isdigit(s[index])){
            path.push_back(s[index]);
            backtrack(result, s, path, index + 1);
            path.pop_back();
        } else {
            // 小写分支
            path.push_back(tolower(s[index]));
            backtrack(result, s, path, index + 1);
            path.pop_back();

            // 大写分支
            path.push_back(toupper(s[index]));
            backtrack(result, s, path, index + 1);
            path.pop_back();
        }
    }
};