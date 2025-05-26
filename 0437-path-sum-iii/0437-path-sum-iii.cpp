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
// class Solution {
// public:
//     int pathSum(TreeNode* root, int targetSum) {
//         int count = 0;
//         backtrack(root, targetSum, 0, count);
//         backtrack(root->left, targetSum, 0, count);
//         backtrack(root->right, targetSum, 0, count);
//         return count;
//     }
// private:
//     void backtrack(TreeNode* node, int targetSum, int sum, int& count){
//         if(!node) return;

//         sum += node->val;

//         if(sum == targetSum){
//             count++;
//         }

//         backtrack(node->left, targetSum, sum, count);
//         backtrack(node->right, targetSum, sum, count);
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

class Solution{
public:
    int pathSum(TreeNode* root, int targetSum){
        if(!root) return 0;

        int count = dfs(root, targetSum);

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
private:
    int dfs(TreeNode* node, long long targetSum){
        if(!node) return 0;

        int count = 0;
        if(targetSum == node->val) count++;

        count += dfs(node->left, targetSum - node->val);
        count += dfs(node->right, targetSum - node->val);

        return count;
    }
};