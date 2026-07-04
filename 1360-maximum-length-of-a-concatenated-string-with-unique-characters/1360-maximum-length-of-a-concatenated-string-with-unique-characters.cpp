class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int mask = 0 ; mask < (1 << n) ; mask++){
            string path = "";
            bool valid = true;
            for(int i = 0 ; i < n ; i++){
                if(mask & (1 << i)){
                    if(canMake(path, arr[i])){
                        path.append(arr[i]);
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid) ans = max(ans, (int)path.size());
        }
        return ans;
    }

    bool canMake(const string& s1, const string& s2){
        int mask = 0;
        for(char c : s1){
            int bit = (1 << (c - 'a'));
            if(mask & bit) return false;
            mask |= bit;
        }

        for(char c : s2){
            int bit = (1 << (c - 'a'));
            if(mask & bit) return false;
            mask |= bit;
        }
        return true;
    }
};