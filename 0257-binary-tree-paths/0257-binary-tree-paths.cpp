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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path; // 当前走过的路径
        dfs(root, path, result);
        return result;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& result){
        if(!node) return;

        // 每到一个新节点, 先把它的值加进路径
        if(!path.empty()) path += "->";
        path += to_string(node->val);

        // 如果是叶子节点(没有左右子节点称为叶子节点), 把路径加入结果集
        if(!node->left && !node->right){
            result.push_back(path);
            return;
        }

        // 递归探索左右子树
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
};