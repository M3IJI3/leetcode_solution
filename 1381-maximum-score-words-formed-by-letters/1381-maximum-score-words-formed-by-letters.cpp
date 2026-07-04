class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // 统计所有可用字符频率
        int have[26]{};
        for(char& c : letters) have[c - 'a']++;

        int n = words.size(), ans = 0;
        for(int mask = 0 ; mask < (1 << n) ; mask++){
            int temp[26];
            copy(begin(have), end(have), temp);

            int currScore = 0;
            bool valid = true;
            for(int i = 0 ; i < n ; i++){
                if(mask & (1 << i)){
                    for(char c : words[i]){
                        if(temp[c - 'a'] == 0){
                            valid = false;
                            break;
                        }
                        temp[c - 'a']--;
                        currScore += score[c - 'a'];
                    }
                }
            }
            if(valid) ans = max(ans, currScore);
        }
        return ans;
    }
};