class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, visited, 0);
        for(bool v : visited){
            if(!v) return false;
        }
        return true;
    }

    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int room){
        visited[room] = true;
        for(int key: rooms[room]){
            if(!visited[key]){
                dfs(rooms, visited, key);
            }
        }
    }
};