class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // DFS: modify elements in place allowed
        // if(start < 0 || start >= arr.size() || arr[start] < 0) return false;
        // if(arr[start] == 0) return true;

        // int jump = arr[i];
        // arr[start] = -1; // 标记为已经访问

        // return canReach(arr, start + jump) || canReach(arr, start - jump);
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        // DFS: modify elements in place not allowed
        int n = arr.size();
        vector<bool> visited(n, false);
        return dfs(arr, start, visited);
    }

    bool dfs(vector<int>& arr, int start, vector<bool>& visited){
        if(start < 0 || start > arr.size() - 1 || visited[start]) return false;
        if(arr[start] == 0) return true;

        visited[start] = true;
        return dfs(arr, start + arr[start], visited) || dfs(arr, start - arr[start], visited); 
    }
};