class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, string> map;
        vector<int> copy = score;

        sort(copy.begin(), copy.end(), greater<int>());
        for(int i = 0 ; i < copy.size() ; i++){
            if(i == 0) map[copy[i]] = "Gold Medal";
            else if(i == 1) map[copy[i]] = "Silver Medal";
            else if(i == 2) map[copy[i]] = "Bronze Medal";
            else map[copy[i]] = std::to_string(i + 1); 
        }

        vector<string> ans;
        for(int num: score){
            ans.push_back(map[num]);
        }
        return ans;
    }
};