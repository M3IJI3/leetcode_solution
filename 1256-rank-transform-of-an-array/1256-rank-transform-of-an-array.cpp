class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans = arr;
        unordered_map<int, int> pos;
        ranges::sort(arr);
        int order = 1;
        for(int i = 0 ; i < n ; i++){
            if(pos.count(arr[i])) continue;
            pos[arr[i]] = order;
            order++; 
        }

        for(int i = 0 ; i < n ; i++){
            ans[i] = pos[ans[i]];
        }
        return ans;
    }
};