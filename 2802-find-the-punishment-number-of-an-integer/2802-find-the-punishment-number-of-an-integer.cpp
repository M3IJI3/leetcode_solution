class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            int square = i * i;
            string s = to_string(square);
            if (dfs(s, 0, 0, 0, i)){
                ans += square;
            }
        }
        return ans;
    }

    bool dfs(string& s, int i, int start, int sum, int target){
        if(i == s.size()){
            return sum == target;
        }

        if(i < s.size() - 1){
            if(dfs(s, i + 1, start, sum, target)){
                return true;
            }
        }

        string sub = s.substr(start, i - start + 1);
        int num = stoi(sub);
        if(sum + num <= target){
            if(dfs(s, i + 1, i + 1, sum + num, target)){
                return true;
            }
        }
        return false;
    }
};