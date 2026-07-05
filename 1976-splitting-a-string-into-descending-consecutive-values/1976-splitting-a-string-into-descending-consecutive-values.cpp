class Solution {
public:
    bool splitString(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            string first = s.substr(0, i + 1);
            __int128 prev = to_int128(first);  // 使用 __int128
            if (dfs(s, prev, i + 1)) return true;
        }
        return false;
    }

    bool dfs(string& s, __int128 prev, int index) {
        if (index == s.size()) return true;

        __int128 num = 0;
        for (int i = index; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');
            if (num > prev) break;
            if (prev - num == 1) {
                if (dfs(s, num, i + 1)) return true;
            }
        }
        return false;
    }

    __int128 to_int128(const string& s) {
        __int128 num = 0;
        for (char c : s) {
            num = num * 10 + (c - '0');
        }
        return num;
    }
};