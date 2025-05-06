class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1, map2;
        int n = s.size();

        for(int i = 0 ; i < n ; i++){
            char a = s[i], b = t[i];

            if((map1.count(a) && map1[a] != b) || (map2.count(b) && map2[b] != a)){
                return false;
            }

            map1[a] = b;
            map2[b] = a;
        }
        return true;
    }
};