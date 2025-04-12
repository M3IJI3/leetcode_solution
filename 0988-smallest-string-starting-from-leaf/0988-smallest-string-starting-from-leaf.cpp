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
    string smallestFromLeaf(TreeNode* root) {
        string result = "~";
        string path;
        dfs();
        return result;
    }

private:
    void dfs(TreeNode* node, string& result, string& path){
        if(!node) return;

        // 将当前走过的路保存进path
        path.push_back('a' + node->val);

        if(!node->left && !node->right){
            string leafToRoot = path;
            reverse(leafToRoot.begin(), leafToRoot.end());
            result = min(result, leafToRoot);
        }

        dfs(node->left, result, path);
        dfs(node->right, result, path);

        path.pop_back();
    }
};