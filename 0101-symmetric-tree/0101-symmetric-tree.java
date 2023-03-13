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
        if (root == null) return true;
        return isSymmetric(root.left, root.right);
    }
    
    private boolean isSymmetric(TreeNode l, TreeNode r) {
        if (l == null || r == null) {
            if (l != null || r != null) {
                return false;
            }
            return true;
        }
        
        return (l.val == r.val) && isSymmetric(l.left, r.right) && isSymmetric(l.right, r.left);
    }
}