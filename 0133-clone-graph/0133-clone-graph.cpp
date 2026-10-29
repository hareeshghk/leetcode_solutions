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
    unordered_map<int, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* cloneRoot = new Node(node->val);
        dfs(node, cloneRoot);
        return cloneRoot;
    }

    void dfs(Node* root, Node* cloneRoot) {
        if (root == nullptr) return;

        if (visited.find(root->val) != visited.end()) return;

        visited[root->val] = cloneRoot;

        for (auto neighbour : root->neighbors) {
            Node* cloneNeighbour;
            
            if (visited.find(neighbour->val) != visited.end()) {
                cloneNeighbour = visited[neighbour->val];
            } else {
                cloneNeighbour = new Node(neighbour->val);
            }
            
            cloneRoot->neighbors.push_back(cloneNeighbour);
            dfs(neighbour, cloneNeighbour);
        }
        return;
    }
};