/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> newlistmap;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        
        auto head_copy = copylist(head);
        
        auto current = head_copy;
        while (current != nullptr) {
            if (current->random != nullptr)
                current->random = newlistmap[current->random];
            current = current->next;
        }
        return head_copy;
    }
    
    Node* copylist(Node *head) {
        if (head == nullptr) return head;
        Node* head_copy = new Node(head->val);
        head_copy->random = head->random;
        newlistmap[head] = head_copy;
        head_copy->next = copylist(head->next);
        return head_copy;
    }
};