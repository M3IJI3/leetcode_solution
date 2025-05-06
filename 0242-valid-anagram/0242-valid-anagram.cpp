class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);

        if(s.size() != t.size()) return false;
        
        for(int i = 0 ; i < s.size() ; i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(count[i] != 0) return false;
        }
        return true;
    }
};