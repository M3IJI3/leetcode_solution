class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ch_index = -1;

        for(int i = 0 ; i < word.size() ; i++){
            if(word[i] == ch){
                ch_index = i;
                break;
            }
        }

        if(ch_index != -1) reverse(word.begin(), word.begin() + ch_index + 1);

        return word;
    }
};