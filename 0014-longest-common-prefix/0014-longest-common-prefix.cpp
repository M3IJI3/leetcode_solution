class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // // 以第一个元素的第一个字符为基准
        // // 从第二个元素开始依次对每一个字符进行比较

        // if(strs.empty()) return "";

        // for(int i = 0 ; i < strs[0].size() ; i++){
        //     char c = strs[0][i];
        //     for(int j = 1 ; j < strs.size() ; j++){
        //         if(c != strs[j][i] || i >= strs[j].size()){
        //             return strs[0].substr(0, i); 
        //         }
        //     }
        // }

        // return strs[0];
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        sort(strs.begin(), strs.end());

        int n = strs.size();
        string start = strs[0];
        string end = strs[n - 1];

        for(int i = 0 ; i < start.size() ; i++){
            if(start[i] != end[i]){
                return start.substr(0, i);
            }
        }

        return start;
    }
};