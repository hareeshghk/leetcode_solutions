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
    int prevValue, minDiff;
    public int minDiffInBST(TreeNode root) {
        prevValue = Integer.MIN_VALUE;
        minDiff = Integer.MAX_VALUE;
        inorderTraverse(root);
        return minDiff;
    }
    
    private void inorderTraverse(TreeNode root) {
        if (root == null) return;
        inorderTraverse(root.left);
        if (prevValue != Integer.MIN_VALUE) minDiff = Math.min(minDiff, root.val-prevValue);
        prevValue = root.val;
        inorderTraverse(root.right);
    }
}