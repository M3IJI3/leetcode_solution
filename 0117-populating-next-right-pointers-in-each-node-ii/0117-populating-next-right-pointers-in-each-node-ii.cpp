/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            int currSize = levelSize;
            vector<Node*> currLevel;
            while(levelSize > 0){
                Node* node = q.front(); q.pop();
                currLevel.push_back(node);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                levelSize--;
            }

            for(int i = 0; i < currSize - 1 ; i++){
                currLevel[i]->next = currLevel[i + 1];
            }
            currLevel[currSize - 1]->next = nullptr;
        } 

        return root;
    }
};









