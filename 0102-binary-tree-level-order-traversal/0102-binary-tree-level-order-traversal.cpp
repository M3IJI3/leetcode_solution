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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back({root->val});

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> path;
            while(levelSize--){
                TreeNode* node = q.front(); q.pop();

                if(node->left){
                    q.push(node->left);
                    path.push_back(node->left->val);
                }

                if(node->right){
                    q.push(node->right);
                    path.push_back(node->right->val);
                }
            }
            if(!path.empty()) ans.push_back(path);
        }
        return ans;
    }
};