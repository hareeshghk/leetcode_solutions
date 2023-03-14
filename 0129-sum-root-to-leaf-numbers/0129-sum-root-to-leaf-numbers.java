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
    Integer answer;
    public int sumNumbers(TreeNode root) {
        answer = new Integer(0);
        
        sumNumbers(root, 0);
        return answer;
    }
    
    void sumNumbers(TreeNode root, int prev) {
        if (root == null) {
            return;
        }
        
        if (root.left == null && root.right == null) {
            answer += prev*10+root.val;
            return;
        }
        
        sumNumbers(root.left, prev*10+root.val);
        sumNumbers(root.right, prev*10+root.val);
    }
}