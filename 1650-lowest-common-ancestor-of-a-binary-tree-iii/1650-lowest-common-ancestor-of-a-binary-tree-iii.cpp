/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> visitednodes;
        
        while (p!=nullptr) {
            visitednodes.insert(p);
            p = p->parent;
        }
        
        while (q!=nullptr) {
            if (visitednodes.find(q) != visitednodes.end()) return q;
            q = q->parent;
        }
        return nullptr;
    }
};