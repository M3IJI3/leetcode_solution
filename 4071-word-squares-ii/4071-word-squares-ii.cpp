class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        ranges::sort(words);
        vector<string> path;
        dfs(words, path);
        return ans;
    }

    void dfs(vector<string>& words, vector<string>& path){
        if(path.size() == 4){
            string &left = path[1];
            string &bottom = path[3];
            string &right = path[2];
            if(bottom[0] == left[3] && bottom[3] == right[3]){
                ans.push_back(path);
            }
            return;
        }

        // 剪枝
        if(path.size() == 2){
            string &top = path[0];
            string &left = path[1];
            if(top[0] != left[0]) return;
        }

        if(path.size() == 3){
            string &top = path[0];
            string & right = path[2];
            if(top[3] != right[0]) return;
        }

        for(int i = 0 ; i < words.size() ; i++){
            if(words[i] == "#") continue;
            string rec = words[i];
            path.push_back(words[i]);
            words[i] = "#";
            dfs(words, path);
            words[i] = rec;
            path.pop_back();
        }

    }
};