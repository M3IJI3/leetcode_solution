class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 1. build graph model
        for(int i = 0 ; i < equations.size() ; i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // 2. do dfs to every search 
        vector<double> res;
        for(auto& q : queries){
            string start = q[0], end = q[1];
            unordered_set<string> visited;
            double result = dfs(start, end, visited);
            res.push_back(result);
        }
        return res;
    }

    double dfs(string curr, string target, unordered_set<string>& visited){
        if(!graph.count(curr) || !graph.count(target)) return -1.0;
        if(curr == target) return 1.0;

        visited.insert(curr);
        for(auto& [next, val] : graph[curr]){
            if(visited.count(next)) continue;
            double sub = dfs(next, target, visited);
            if(sub != -1.0) return val * sub;
        }
        return -1.0;
    }
};