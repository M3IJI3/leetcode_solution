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
//     int longestUnivaluePath(TreeNode* root) {
//         // 定义动态数组存储当前路径
//         vector<int> path;
//         return dfs(root, path);
//     }

// private:
//     int dfs(TreeNode* node, vector<int>& path){
//         if(!node) return 0;
        
//         // 用于存储当前最大长度
//         int maxLen = 0;

//         // 从当前节点出发判断左右子树的值是否与父节点值相同
//         if(node->val == node->left->val){
//             // 1. 将值存入当前路径
//             path.push_back(node->val);
//             // 2. 接着, 满足左子树相同, 递归进入左边路径
//             dfs(node->left, path);
//         }

//         // 同理可得右子树
//         if(node->val == node->right->val){
//             path.push_back(node->val);
//             dfs(node->right, path);
//         }

//         // 更新maxLen的值
//         maxLen = max(maxLen, path.size());
//         path.pop_back();

//         return maxLen;
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

class Solution{
public:
    int maxLen = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxLen;
    }
private:
    int dfs(TreeNode* node){
        if(!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftPath = 0, rightPath = 0;

        if(node->left && node->left->val == node->val){
            leftPath = left + 1;
        }        

        if(node->right && node->right->val == node->val){
            rightPath = right + 1;
        }

        // 最大路径长度是 leftPath + rightPath = 4，这是当前节点作为“中间点”的最大值 → 所以更新 maxLen
        maxLen = max(maxLen, leftPath + rightPath);

        // 返回值只能是 max(leftPath, rightPath)，因为你只能选择一个方向继续往上走！
        return max(leftPath, rightPath);
    }
};