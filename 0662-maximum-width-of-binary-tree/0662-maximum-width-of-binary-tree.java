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
        
        Deque<Pair<TreeNode, Integer>> bfs_queue = new LinkedList<>();
        
        bfs_queue.addLast(new Pair<>(root, 0));
        
        int answer = 1;
        
        while (!bfs_queue.isEmpty()) {
            int size = bfs_queue.size();
            
            answer = Math.max(answer, bfs_queue.getLast().getValue() - bfs_queue.getFirst().getValue() + 1);
            while (size-- != 0) {
                Pair<TreeNode, Integer> cur = bfs_queue.removeFirst();
                
                if (cur.getKey().left != null) {
                    bfs_queue.addLast(new Pair<>(cur.getKey().left, 2* cur.getValue()));
                }
                
                if (cur.getKey().right != null) {
                    bfs_queue.addLast(new Pair<>(cur.getKey().right, 2* cur.getValue() + 1));
                }
            }
        }
        
        return answer;
    }
}