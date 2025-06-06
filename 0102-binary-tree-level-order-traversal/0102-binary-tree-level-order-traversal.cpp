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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        // if(!root) return {};

        // queue<TreeNode*> q;
        // q.push(root);
        // vector<vector<int>> ans;

        // while(!q.empty()){
        //     int levelSize = q.size();
        //     vector<int> curr;
        //     while(levelSize--){
        //         TreeNode* node = q.front(); q.pop();
        //         curr.push_back(node->val);
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        //     ans.push_back(curr);
        // }
        // return ans;
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int level){
        if(!node) return;

        if(level == res.size()) res.push_back({});
        res[level].push_back(node->val);

        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
};