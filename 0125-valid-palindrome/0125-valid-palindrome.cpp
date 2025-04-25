class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(char c : s){
            if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
                temp += tolower(c);
            } else if(isdigit(c)){
                temp += c;
            }
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