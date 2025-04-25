class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;

        int i = 0;
        int numI = 0, numD = s.size();

        while(i < s.size()){
            if(s[i] == 'I'){
                ans.push_back(numI);
                numI++;
            } else {
                ans.push_back(numD);
                numD--;
            }
            i++;
        }

        ans.push_back(numI);
        return ans;
    }
};