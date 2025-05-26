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
    vector<vector<int>> ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }
private:
    void dfs(TreeNode* node, int remain, vector<int>& path){
        if(!node) return;

        path.push_back(node->val);
        remain -= node->val;

        if(!node->left && !node->right && remain == 0){
            ans.push_back(path);
        }

        dfs(node->left, remain, path);
        dfs(node->right, remain, path);

        path.pop_back();
    }
};