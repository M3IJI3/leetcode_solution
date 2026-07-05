class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int ans = 0;
        for(int mask = 0 ; mask < (1 << m) ; mask++){
            vector<int> diff(n, 0);
            bool valid = true;
            int count = 0;
            for(int i = 0 ; i < m ; i++){
                if(mask & (1 << i)){
                    count++;
                    int from = requests[i][0], to = requests[i][1];
                    diff[from]--;
                    diff[to]++;
                }
            }

            for(int d : diff){
                if(d != 0){
                    valid = false;
                    break;
                }
            }
            if(valid) ans = max(ans, count);
        }
        return ans;
    }
};