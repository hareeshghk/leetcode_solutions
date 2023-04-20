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
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        
        Deque<TreeNode> bfsQueue = new LinkedList<>();
        
        root.val = 0;
        bfsQueue.addLast(root);
        
        int answer = 1;
        
        while (!bfsQueue.isEmpty()) {
            int size = bfsQueue.size();
            
            answer = Math.max(answer, bfsQueue.getLast().val - bfsQueue.getFirst().val + 1);
            while (size-- != 0) {
                TreeNode cur = bfsQueue.removeFirst();
                
                if (cur.left != null) {
                    cur.left.val = 2 * cur.val;
                    bfsQueue.addLast(cur.left);
                }
                
                if (cur.right != null) {
                    cur.right.val = 2 * cur.val + 1;
                    bfsQueue.addLast(cur.right);
                }
            }
        }
        
        return answer;
    }
}