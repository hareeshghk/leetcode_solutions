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
    List<TreeNode> answer;
    HashMap<String, Boolean> seen;
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        answer = new ArrayList<>();
        seen = new HashMap<>();
        
        postOrderTraversal(root);
        return answer;
    }
    
    String postOrderTraversal(TreeNode root) {
        if (root == null) return "";
        
        String leftStr = postOrderTraversal(root.left);
        String rightStr = postOrderTraversal(root.right);
        
        String representation = leftStr + 'L' + Integer.toString(root.val) + 'M' + rightStr + 'R';
        
        if (!seen.containsKey(representation)) {
            seen.put(representation, false);
            return representation; 
        }
        
        if (seen.get(representation) == true) return representation;
        
        seen.put(representation, true);
        answer.add(root);
        return representation;
    }
}