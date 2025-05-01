// TLE
// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int left = 0;
//         string temp;
//         for (int right = 0; right < s2.size(); right++) {
//             temp += s2[right];
//             while (temp.size() > s1.size()) {
//                 temp = temp.substr(1);
//                 left++;
//             }
//             if (isPermutation(s1, temp))
//                 return true;
//         }
//         return false;
//     }
// private:
//     bool isPermutation(string& sa, string& sb) {
//         unordered_map<char, int> map_a, map_b;

//         for (char c : sa) {
//             map_a[c]++;
//         }
//         for (char c : sb) {
//             map_b[c]++;
//         }
//         return map_a == map_b;
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class Solution{
public:
    bool checkInclusion(string s1, string s2){
        if(s1.size() > s2.size()) return false;

        vector<int> count1(26,0), count2(26, 0);

        // 统计s1的字符频率
        for(char c : s1) count1[c - 'a']++;

        // 初始化前s1.size() 个字符频率
        for(int i = 0 ; i < s1.size() ; i++){
            count2[s2[i] - 'a']++;
        }

        if(count1 == count2) return true;

        for(int i = s1.size() ; i < s2.size() ; i++){
            count2[s2[i] - 'a']++;
            count2[s2[i - s1.size()] - 'a']--;

            if(count1 == count2) return true;
        }

        return false;
    }
};