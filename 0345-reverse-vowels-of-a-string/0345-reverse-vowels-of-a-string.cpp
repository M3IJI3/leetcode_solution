class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;

        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};

        while(left < right){

            char leftChar = s[left];
            char rightChar = s[right];

            if(!set.count(tolower(leftChar))) left++;
            if(!set.count(tolower(rightChar))) right--;

            if(set.count(tolower(leftChar)) && set.count(tolower(rightChar))){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }
        }
        return s;
    }
};