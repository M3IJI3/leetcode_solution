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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        // 只能看到每一层的最后一个节点

        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        vector<int> ans;

        while(!q.empty()){
            int levelSize = q.size();
            while(levelSize--){
                TreeNode* node = q.front(); q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp[temp.size() - 1]);
            temp.clear();
        }

        return ans;
    }
};