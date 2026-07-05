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
                string temp = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
                ans.push_back(temp);
            }
            return;
        }

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