class Solution {
    int ans = 0;
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> have(26, 0);
        for(char c: letters){
            have[c - 'a']++;    // 统计所有可用的字符
        }

        dfs(words, score, have, 0, 0);
        return ans;
    }

    void dfs(vector<string>& words, vector<int>& score, vector<int>& have, int currScore, int i){
        if(i == words.size()){
            ans = max(ans, currScore);
            return;
        }

        dfs(words, score, have, currScore, i + 1);

        bool ok = true;
        for(char& c : words[i]){
            if(have[c - 'a'] == 0){
                ok = false;
            }
            have[c - 'a']--;
            currScore += score[c - 'a'];
        }

        if(ok){
            dfs(words, score, have, currScore, i + 1);
        }

        for(char& c : words[i]){
            have[c - 'a']++;
        }
    }
};