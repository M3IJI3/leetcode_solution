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
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<int> sums;
        dfs(root, path, sums, 0);
        for(int sum: sums){
            if(sum == targetSum)
                return true;
        }
        return false;
    }   

private:
    void dfs(TreeNode* node, vector<int>& path, vector<int>& sums, int sum){
        if(!node) return;

        path.push_back(node->val);
        sum += node->val;
    
        if(!node->left && !node->right){
             sums.push_back(sum);
        }

        dfs(node->left,  path, sums, sum);
        dfs(node->right, path, sums, sum);
        path.pop_back();
    }
};