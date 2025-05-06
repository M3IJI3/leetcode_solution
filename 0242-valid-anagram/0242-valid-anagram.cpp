class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sfreq(26, 0);
        vector<int> tfreq(26, 0);

        if(s.size() != t.size()) return false;

        for(int i = 0 ; i < s.size() ; i++){
            char cs = s[i];
            char ct = t[i];

            sfreq[cs - 'a']++;
            tfreq[ct - 'a']++;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(sfreq[i] != tfreq[i]) return false;
        }

        return true;
    }
};