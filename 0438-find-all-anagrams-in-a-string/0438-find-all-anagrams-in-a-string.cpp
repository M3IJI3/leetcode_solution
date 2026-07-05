class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> s_cnt(26, 0);
        vector<int> p_cnt(26, 0);
        for(char c : p) p_cnt[c - 'a']++;

        int l = 0, n = p.size();
        vector<int> ans;
        for(int r = 0 ; r < s.size() ; r++){
            s_cnt[s[r] - 'a']++;
            int l = r - n + 1;
            if(l < 0) continue;
            if(s_cnt == p_cnt) ans.push_back(l);
            s_cnt[s[l] - 'a']--;
        }
        return ans;
    }
};