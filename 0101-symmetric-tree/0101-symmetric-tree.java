/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isSame(root.left, root.right);
    }

    private boolean isSame(TreeNode p, TreeNode q)
    {
        if(p == null || q == null) return p == q;

        return (p.val == q.val) && isSame(p.left, q.right) && isSame(p.right, q.left);
    }
}