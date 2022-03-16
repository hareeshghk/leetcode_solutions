/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> created;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        
        if (created.find(node) != created.end()) return created[node];
        
        auto head = new Node(node->val);
        created[node] = head;
        
        for (auto neighbor : node->neighbors) {
            head->neighbors.push_back(cloneGraph(neighbor));
        }
        return head;
    }
};