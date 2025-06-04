class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if(!dict.count(end)) return -1;

        queue<pair<string, int>> q;
        q.push({start, 0});
        unordered_set<string> visited;
        visited.insert(start);

        vector<char> genes = {'A', 'G', 'C', 'T'};
        while(!q.empty()){
            auto [curr, steps] = q.front();
            q.pop();

            if(curr == end) return steps;
            for(int i = 0 ; i < curr.size() ; i++){
                char old = curr[i];
                for(char& gene : genes){
                    if(old == gene) continue;

                    curr[i] = gene;
                    if(!visited.count(curr) && dict.count(curr)){
                        q.push({curr, steps + 1});
                        visited.insert(curr);
                    }
                }
                curr[i] = old;
            }
        }
        return -1;
    }
};