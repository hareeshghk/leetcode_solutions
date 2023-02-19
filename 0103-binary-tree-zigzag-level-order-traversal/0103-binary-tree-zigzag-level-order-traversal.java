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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> main;
        main = new ArrayDeque<>();
        List<List<Integer>> answer = new ArrayList<>();
        
        if (root == null) return answer;
        
        main.add(root);
        int turn = 1;
        
        while (!main.isEmpty()) {
            int x = main.size();
            List<Integer> tempList = new ArrayList<>();
            for (int i = 0; i < x; ++i) {
                TreeNode cur = main.poll();
                tempList.add(cur.val);
                if (cur.left != null) {
                    main.add(cur.left);
                }
                if (cur.right != null) {
                    main.add(cur.right);
                }
            }
            
            if(turn < 0) {
                Collections.reverse(tempList);
            }
            turn *= -1;
            answer.add(tempList);
        }
        return answer;
    }
}