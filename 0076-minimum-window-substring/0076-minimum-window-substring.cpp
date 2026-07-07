class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return "";

        unordered_map<char, int> need;
        for(char c : t) need[c]++;

        unordered_map<char, int> window;
        int left = 0 , right = 0;
        int valid = 0;
        int minLen = INT_MAX, start = 0;
        while(right < m){
            char c = s[right];
            right++;

            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }

            while(valid == need.size()){
                if(right - left < minLen){
                    start = left;
                    minLen = right - left;
                }

                char d = s[left];
                left++;

                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};