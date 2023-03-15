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
    int maxDepth;
    boolean triggered;
    public boolean isCompleteTree(TreeNode root) {
        maxDepth = getDepth(root);
        triggered = false;
        return traverse(root, 1);
    }
    
    int getDepth(TreeNode root) {
        if (root == null) return 0;
        
        return Math.max(getDepth(root.left), getDepth(root.right))+1; 
    }
    
    boolean traverse(TreeNode root, int currentDepth) {
        if (root == null) {
            if (currentDepth < maxDepth){
                return false;
            }
            
            if (currentDepth > maxDepth) {
                return true;
            }
            
            triggered = true;
            return true;
        }
        
        if (triggered && currentDepth == maxDepth) return false;
        
        return traverse(root.left, currentDepth + 1) && traverse(root.right, currentDepth + 1);
    }
}