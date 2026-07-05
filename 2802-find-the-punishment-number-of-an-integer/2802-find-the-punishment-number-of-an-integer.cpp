class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0 ;
        for(int i = 1 ; i <= n ; i++){
            int target = i * i;
            string s = to_string(target);
            if(dfs(s, 0, 0, i)){
                ans += target;
            }
        }
        return ans;
    }

    bool dfs(string& s, int index, int sum, int target){
        if(index == s.size()){
            return sum == target;
        }

        int num = 0;
        for(int i = index ; i < s.size() ; i++){
            num = num * 10 + (s[i] - '0');
            if(sum + num > target) return false;
            if(dfs(s, i + 1, sum + num, target)){
                return true;
            }
        }
        return false;
    }
};