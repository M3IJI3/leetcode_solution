class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 1. build the graph
        for(int i = 0 ; i < equations.size() ; i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> results;
        for(auto& query : queries){
            string start = query[0];
            string end = query[1];
            unordered_set<string> visited;
            double res = dfs(start, end, visited);
            results.push_back(res);
        }
        return results;
    }

    double dfs(string curr, string target, unordered_set<string>& visited){
        if(!graph.count(curr)) return -1.0;
        if(curr == target) return 1.0;

        visited.insert(curr);
        for(auto& [next, weight] : graph[curr]){
            if(visited.count(next)) continue;
            double sub = dfs(next, target, visited);
            if(sub != -1.0) return weight * sub;
        }
        return -1.0;
    }
};