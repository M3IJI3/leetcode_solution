class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;

        int left = 0;
        string temp;
        for(int right = 0 ; right < s.size() ; right++){
            temp += s[right];

            // 控制滑动窗口
            while(temp.size() > 10){
                left++;
                temp = temp.substr(1);
            }

            if(temp.size() == 10){
                map[temp]++;
            }
        }

        vector<string> ans;
        for(auto& [s, count] : map){
            if(count > 1) ans.push_back(s);
        }

        return ans;
    }
};