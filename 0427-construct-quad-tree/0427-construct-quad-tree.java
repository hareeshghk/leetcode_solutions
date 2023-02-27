/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};
*/

class Solution {
    public Node construct(int[][] grid) {
        int n = grid.length;
        
        return getQuadTree(grid, 1, n, 1, n);
    }
    
    Node getQuadTree(int[][] grid, int startx, int endx, int starty, int endy) {
        if (startx == endx) {
            return new Node(grid[starty-1][startx-1]==1, true);
        }
        
        Node topLeft = getQuadTree(grid, startx, (startx+endx)/2, starty, (starty+endy)/2);
        Node topRight = getQuadTree(grid, ((startx+endx)/2)+1, endx, starty, (starty+endy)/2);
        Node bottomLeft = getQuadTree(grid, startx, (startx+endx)/2, ((starty+endy)/2) + 1, endy);
        Node bottomRight = getQuadTree(grid, ((startx+endx)/2) + 1, endx, ((starty+endy)/2)+1, endy);
        
        
        if (topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf
            && topLeft.val == topRight.val && topRight.val == bottomLeft.val
            && bottomLeft.val == bottomRight.val) {
            return new Node(topLeft.val, true);
        }
        
        Node current = new Node(true, false);
        
        current.topLeft = topLeft;
        current.topRight = topRight;
        current.bottomLeft = bottomLeft;
        current.bottomRight = bottomRight;
        
        return current;
    }
}