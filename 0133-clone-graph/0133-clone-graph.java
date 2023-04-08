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
        
        Node copyNode;
        if (copyTreeNodes.getOrDefault(node.val, null) == null) {
            copyNode = new Node(node.val);
            copyTreeNodes.put(node.val, copyNode);
        } else {
            return copyTreeNodes.get(node.val);
        }
        
        for (Node neighbor : node.neighbors) {
            copyNode.neighbors.add(cloneGraph(neighbor));
        }
        
        return copyNode;
    }
}