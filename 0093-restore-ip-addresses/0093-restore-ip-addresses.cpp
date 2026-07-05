class Solution {
    vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> path; 
        dfs(s, path, 0);
        return ans;
    }

    void dfs(string& s, vector<string>& path, int index){
        if(path.size() == 4){
            if(index == s.size()){
                string tmp = "";
                for(int i = 0 ; i < path.size() ; i++){
                    if(i == 0) tmp.append(path[i]);
                    else tmp.append(string(".") + path[i]);
                }
                ans.push_back(tmp);
            }
            return;
        }

        int remain = s.size() - index;
        if(remain > 0 && path.size() == 4) return;

        for(int i = 1 ; i <= 3 && i + index <= s.size() ; i++){
            string sub = s.substr(index, i);
            if(sub.size() > 1 && sub[0] == '0') break;
            int segment = stoi(sub);
            if(segment > 255) break;
            path.push_back(sub);
            dfs(s, path, i + index);
            path.pop_back();
        }
    }
};