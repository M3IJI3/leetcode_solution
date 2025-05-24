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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // bfs
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> path;
            while(levelSize--){
                TreeNode* node = q.front(); q.pop();
                path.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            ans.insert(ans.begin(), path);
        }

        return ans;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        // dfs
        // vector<vector<int>> ans;
        // dfs(ans, 0, root);
        // reverse(ans.begin(), ans.end());
        // return ans;
    }
// private:
//     void dfs(vector<vector<int>>& ans, int depth, TreeNode* node){
//         if(!node) return;

//         if(depth == ans.size()) ans.push_back({});

//         ans[depth].push_back(node->val);
//         dfs(ans, depth + 1, node->left);
//         dfs(ans, depth + 1, node->right);
//     }
};