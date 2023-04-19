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
    int answer = 0;
    public int longestZigZag(TreeNode root) {
        if (root == null) return 0;
        answer = Math.max(longestZigZag(root.left, 0)+1, answer);
        answer = Math.max(longestZigZag(root.right, 1)+1, answer);
        return Math.max(0, answer-1);
    }
    
    private int longestZigZag(TreeNode root, int dir) {
        if (root == null) {
            return 0;
        }
        
        int count1 = longestZigZag(root.left, 0);
        int count2 = longestZigZag(root.right, 1);
        
        answer = Math.max(answer, count1 + 1);
        answer = Math.max(answer, count2 + 1);
        if (dir == 0) {
            return count2 + 1;
        } else {
            return count1 + 1;
        }
    }
}