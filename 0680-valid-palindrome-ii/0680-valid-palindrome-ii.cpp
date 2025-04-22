// TLE
// class Solution {
// public:
//     bool validPalindrome(string s) {
//         // 1. 首先判断原本是否为回文串
//         if(isPalindrome(s)) return true;
        
//         // 2. 移除某一个字符后再开始判断是否为回文串
//         string temp;
//         for(int i = 0 ; i < s.size() ; i++){
//             temp = s;
//             temp.erase(i, 1);
//             if(isPalindrome(temp)) return true;
//         }
//         return false;
//     }
// private:
//     bool isPalindrome(const string& s){
//         int left = 0, right = s.size() - 1;

//         while(left < right){
//             if(s[left] != s[right]) return false;
//             left++;
//             right--;
//         }

//         return true;
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

class Solution{
public:
    bool validPalindrome(string s){
        int left = 0, right = s.size() - 1;

        while(left < right){
            if(s[left] != s[right]){
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }
private:
    bool isPalindrome(const string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};