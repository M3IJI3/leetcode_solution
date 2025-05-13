class Solution {
public:
    bool isPalindrome(string s) {
        // string temp;
        // for(char c : s){
        //     // isalnum() 自动判断是字母还是数字
        //     if(isalnum(c)) temp += tolower(c);
        // }
        
        // int head = 0, tail = temp.size() - 1;

        // while(head < tail){
        //     if(temp[head] != temp[tail]) return false;
        //     head++;
        //     tail--;
        // }

        // return true;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        int left = 0, right = s.size() - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;

            if(tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }
        return true;
    }
};