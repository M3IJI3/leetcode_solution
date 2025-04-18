// class Solution {
// public:
//     string reverseStr(string s, int k) {
//         if(k > s.size()){
//             reverse(s.begin(), s.end());
//             return s;
//         }

//         int left = 0, right = k - 1;
//         while(right <= s.size()){
//             reverse(s.begin() + left , s.begin() + right + 1);

//             left += 2 * k;
//             right += 2 * k;
//         }
//         return s;
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0 ; i < n ; i += 2 * k){
            int r = min(i + k, n);
            reverse(s.begin() + i, s.begin() + r);
        }
        return s;
    }
};