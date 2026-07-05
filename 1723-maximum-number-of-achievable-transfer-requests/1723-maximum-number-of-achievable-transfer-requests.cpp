class Solution {
    int ans = 0;
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> diff(n, 0);
        dfs(requests, diff, 0, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& requests, vector<int>& diff, int count, int index){
        if(index == requests.size()){
            for(int d : diff){
                if(d != 0) return;
            }
            ans = max(ans, count);
            return;
        }

        dfs(requests, diff, count, index + 1);

        int from = requests[index][0];
        int to = requests[index][1];
        diff[from]--;
        diff[to]++;
        dfs(requests, diff, count + 1, index + 1);
        diff[from]++;
        diff[to]--;
    }
};