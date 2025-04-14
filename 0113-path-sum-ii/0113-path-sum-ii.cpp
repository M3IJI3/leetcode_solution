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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, result, path, targetSum, 0);
        return result;
    }
private:
    void dfs(TreeNode* node, vector<vector<int>>& result, vector<int>& path, int targetSum, int sum){
        // if(sum == targetSum && !node){
        //     result.push_back(path);
        //     return;
        // }

        // sum += node->val;
        // dfs(node->left, result, path, targetSum, sum);
        // dfs(node->right, result, path, targetSum, sum);
        // path.pop_back();
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        if(!node) return;

        path.push_back(node->val);
        sum += node->val;

        // 如果是叶子节点并且路径和等于目标值
        if(!node->left && !node->right && sum ==  targetSum){
            result.push_back(path);
        }

        dfs(node->left, result, path, targetSum, sum);
        dfs(node->right, result, path, targetSum, sum);

        path.pop_back();
    }
};