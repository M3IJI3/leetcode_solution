class Solution {
    int ans = 0;
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> diff(n, 0);
        dfs(requests, diff, 0, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& requests, vector<int>& diff, int index, int count){
        if(index == requests.size()){
            for(int d : diff){
                if(d != 0) return;
            }
            ans = max(ans, count);
            return;
        }

        dfs(requests, diff, index + 1, count);

        int from = requests[index][0];
        int   to = requests[index][1];
        diff[from]--;
        diff[to]++;
        dfs(requests, diff, index + 1, count + 1);
        diff[to]--;
        diff[from]++;
    }
};

// 每栋楼 from 的员工数目 == 该楼 to 的员工数数目
// 组合不同的请求列表, 保证变化量为0
