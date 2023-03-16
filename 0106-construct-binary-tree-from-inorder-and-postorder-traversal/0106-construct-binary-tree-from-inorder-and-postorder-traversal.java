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
    HashMap<Integer, Integer> locator;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        locator = new HashMap<>();
        
        for (int i = 0; i < inorder.length; ++i) {
            locator.put(inorder[i], i);
        }
        
        return buildTree(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1);
    }
    
    private TreeNode buildTree(int[] inOrder, int li, int hi, int[] postOrder, int lp, int hp) {
        if (hi < li) {
            return null;
        }
        
        if (hi == li) {
            return new TreeNode(inOrder[li]);
        }
        
        int div = locator.get(postOrder[hp]);
        
        int leftTreeNumElements = div - li;
        int rightTreeNumElements = hi - div;
        
        TreeNode root = new TreeNode(postOrder[hp]);
        
        root.left = buildTree(inOrder, li, div-1, postOrder, lp, lp+leftTreeNumElements-1);
        root.right = buildTree(inOrder, div+1, hi, postOrder, lp+leftTreeNumElements, hp-1);
        return root;
    }
}