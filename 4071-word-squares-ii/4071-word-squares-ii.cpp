class Solution {
    vector<vector<string>> ans;
    vector<bool> visited;
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        ranges::sort(words);
        visited = vector<bool>(n, false);
        vector<string> path;
        dfs(words, path);
        return ans;
    }

    void dfs(vector<string>& words, vector<string>& path){
        if(path.size() == 4){
            string &top = path[0], &left = path[1], &right = path[2], &bottom = path[3];
            if(top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] && bottom[3] == right[3]){
                ans.push_back(path);
            }
            return;
        }

        for(int i = 0 ; i < words.size() ; i++){
            if(visited[i]) continue;

            visited[i] = true;
            path.push_back(words[i]);
            dfs(words, path);
            path.pop_back();
            visited[i] = false;
        }

    }
};