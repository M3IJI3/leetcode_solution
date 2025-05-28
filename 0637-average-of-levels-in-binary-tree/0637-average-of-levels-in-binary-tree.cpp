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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;

        while(!q.empty()){
            int levelSize = q.size();
            int count = levelSize;
            long long sum = 0;
            while(levelSize--){
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            double avg = (double)sum / (double)count;
            ans.push_back(avg); 
        }
        return ans;
    }
};