class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        return dfs(arr, visited, start);
    }

    bool dfs(vector<int>& arr, vector<bool>& visited, int start){
        if(start < 0 || start >= arr.size()) return false;
        if(visited[start]) return false;
        visited[start] = true;
        if(arr[start] == 0) return true;
        return dfs(arr, visited, start + arr[start]) || dfs(arr, visited, start - arr[start]);
    }
};