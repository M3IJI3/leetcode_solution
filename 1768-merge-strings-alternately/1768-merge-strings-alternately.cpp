class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len = word1.size() + word2.size();
        int w1_index = 0;
        int w2_index = 0;
        int overlap = min(word1.size(), word2.size());
        string ans;

        for(int i = 0 ; i < 2 * overlap ; i++){
            if(i % 2 == 0){
                ans += word1[w1_index];
                w1_index++;
            } else {
                ans += word2[w2_index];
                w2_index++;
            }
        }

        if(word1.size() > word2.size()){
            ans += word1.substr(overlap, word1.size());
        } else {
            ans += word2.substr(overlap, word2.size());
        }


        return ans;
    }
};