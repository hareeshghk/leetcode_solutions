/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    HashMap<Integer, Node> copyTreeNodes = new HashMap<>();
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        
        Node copyNode = copyTreeNodes.getOrDefault(node.val, null);
        
        if (copyNode != null) {
            return copyNode;
        }
        
        copyNode = new Node(node.val);
        copyTreeNodes.put(node.val, copyNode);
        
        for (Node neighbor : node.neighbors) {
            copyNode.neighbors.add(cloneGraph(neighbor));
        }
        
        return copyNode;
    }
}