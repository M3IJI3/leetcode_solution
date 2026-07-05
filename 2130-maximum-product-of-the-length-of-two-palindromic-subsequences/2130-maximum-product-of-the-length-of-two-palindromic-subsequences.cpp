class Solution {
    int ans = 0;
public:
    int maxProduct(string s) {
        string p1,p2;
        dfs(s, p1, p2, 0);
        return ans;
    }

    void dfs(string& s, string& p1, string& p2, int index){
        if(index == s.size()){
            if(isPalindrome(p1) && isPalindrome(p2)){
                int product = p1.size() * p2.size();
                ans = max(ans, product);
            }
            return;
        }

        dfs(s, p1, p2, index + 1);

        p1.push_back(s[index]);
        dfs(s, p1, p2, index + 1);
        p1.pop_back();

        p2.push_back(s[index]);
        dfs(s, p1, p2, index + 1);
        p2.pop_back();
    }

    bool isPalindrome(const string& p){
        int l = 0, r = p.size() - 1;
        while(l < r){
            if(p[l] != p[r]) return false;
            l++; r--;
        }
        return true;
    }
};