/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
     unordered_map<Node*, Node*> old2new;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return dfs(node);
    }

    Node* dfs(Node* node){
        if(!node) return nullptr;
        if(old2new.count(node)){
            return old2new[node];
        }

        Node* copy = new Node(node->val);
        old2new[node] = copy; 
        for(auto neighbor : node->neighbors){
            copy->neighbors.push_back(dfs(neighbor));
        }
        return copy;
    }
};











