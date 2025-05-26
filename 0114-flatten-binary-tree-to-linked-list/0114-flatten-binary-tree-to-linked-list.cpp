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
    // TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        // dfs
        // if(!root) return;

        // flatten(root->right);
        // flatten(root->left);

        // root->right = prev;
        // root->left = nullptr;
        // prev = root;
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        // bfs
        if(!root) return;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()){
            TreeNode* node = stk.top(); stk.pop();

            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);

            if(!stk.empty()) node->right = stk.top();
            node->left = nullptr;
        }
    }
};