class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(end)) return 0;

        queue<pair<string, int>> q;
        q.push({begin, 1});
        unordered_set<string> visited;
        visited.insert(begin);

        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();

            if(word == end) return steps;

            for(int i = 0 ; i < word.size() ; i++){
                string next = word;
                for(char c = 'a' ; c <= 'z' ; c++){
                    next[i] = c;
                    if(dict.count(next) && !visited.count(next)){
                        q.push({next, steps + 1});
                        visited.insert(next);
                    }
                }
            }
        }
        return 0;
    }
};