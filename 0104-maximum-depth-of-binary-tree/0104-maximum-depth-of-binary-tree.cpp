/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // dfs
        // if(!root) return 0;
        // return 1 + max(maxDepth(root->left), maxDepth(root->right));
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        // bfs
        if(!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty()){
            int levelSize = q.size();
            while(levelSize > 0){
                TreeNode* node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                levelSize--;
            }
            depth++;
        }
        return depth;
    }
};