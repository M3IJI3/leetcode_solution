class Solution {
public:
    int numberOfSubstrings(string s) {
        // TLE
        // int ans = 0;
        // unordered_set<char> need = {'a', 'b', 'c'};
        // unordered_set<char> valid;
        // // 选择起始点
        // for(int left = 0 ; left < s.size() - 2 ; left++){
        //     for(int right = left ; right < s.size() ; right++){
        //         char letter = s[right];
        //         valid.insert(letter);
                
        //         if(valid == need){
        //             ans++;
        //         }
        //     }
        //     valid.clear();
        // }
        // return ans;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        vector<int> count(3, 0); // a = 0, b = 1, c = 2
        int left = 0, res = 0;

        for(int right = 0 ; right < s.size() ; right++){
            count[s[right] - 'a']++;

            // 窗口满足包含 a, b, c
            while(count[0] > 0 && count[1] > 0 && count[2] > 0){
                count[s[left] - 'a']--;
                left++;
            } 

            res += left;
        }
        return res;
    }
};