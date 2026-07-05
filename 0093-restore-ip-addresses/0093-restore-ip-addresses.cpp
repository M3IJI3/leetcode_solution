class Solution {
    vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> path;
        dfs(s, path, 0);
        return ans;
    }

    void dfs(string& s, vector<string>& path, int index){
        if(index == s.size()){
            if(path.size() == 4){
                string ip = "";
                for(int i = 0 ; i < path.size() ; i++){
                    if(i == 0) ip.append(path[i]);
                    else ip.append(string(".") + path[i]);
                }
                ans.push_back(ip);
            }
            return;
        }

        // 剪枝: 剩下的数字每个一位, 也不够
        int remain = s.size() - index;
        if(path.size() + remain < 4) return;
        if(path.size() == 4) return;

        for(int i = index ; i < s.size() ; i++){
            string sub = s.substr(index, i - index + 1);
            // 去掉前导 0;
            if(sub.size() != 1 && sub[0] == '0') continue; 
            int segment = stoi(sub);
            if(segment > 255) break;
            path.push_back(sub);
            dfs(s, path, i + 1);
            path.pop_back();
        }
    }
};