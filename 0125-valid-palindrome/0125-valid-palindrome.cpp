class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(char c : s){
            if(isalnum(c)) temp += tolower(c);
        }
        
        int head = 0, tail = temp.size() - 1;

        while(head < tail){
            if(temp[head] != temp[tail]) return false;
            head++;
            tail--;
        }

        return true;
    }
};