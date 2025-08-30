#include <cmath>

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
        Node *p_c, *q_c;
        p_c = p;
        q_c = q;
        
        int p_len=0,q_len=0;
        
        while (p_c!=nullptr) {
            ++p_len;
            p_c = p_c->parent;
        }
        
        while (q_c!=nullptr) {
            ++q_len;
            q_c = q_c->parent;
        }
        
        if (p_len < q_len) {
            swap(p,q);
        }
        
        for (int i = 0; i < abs(p_len-q_len); ++i) {
            p = p->parent;
        }
        
        while (p != nullptr || q!=nullptr) {
            if(p==q) return p;
            p = p->parent;
            q = q->parent;
        }
        return nullptr;
    }
};
