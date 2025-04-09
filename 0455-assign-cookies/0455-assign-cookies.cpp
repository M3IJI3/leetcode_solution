class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // int ans = 0;

        // for(int i = 0 ; i < g.size() ; i++){
        //     for(int j = 0 ; j < s.size() ; j++){
        //         if(g[i] <= s[j]){
        //             ans++;
        //             s[j] = -1;
        //             break;
        //         }
        //     }
        // }
        // return ans;
        ////////////////////////////////////////////
        // 贪心算法依赖排序
        // 优先用最小的饼干满足胃口最小的孩子
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        int i = 0;
        int j = 0;

        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                ans++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};