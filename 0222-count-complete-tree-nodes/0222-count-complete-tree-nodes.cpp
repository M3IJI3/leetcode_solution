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
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        if(leftDepth == rightDepth){
            return (1 << leftDepth) + countNodes(root->right);
        } else {
            return (1 << rightDepth) + countNodes(root->left);
        }
    }
private:
    int depth(TreeNode* node){
        int d = 0;
        while(node){
            node = node->left;
            d++;
        }
        return d;
    }
};