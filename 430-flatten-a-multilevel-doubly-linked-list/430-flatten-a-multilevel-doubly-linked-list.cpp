/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // Node *current = head;
        flattenandreturntail(head);
        // while (current != nullptr) {
        //     if(current->child == nullptr) {
        //         current = current->next;
        //     } else {
        //         auto temp = current->next;
        //         auto child = current->child;
        //         current->next = child;
        //         child->prev = current;
        //         auto tail = flattenandreturntail(current->next);
        //         tail->next = temp;
        //         if (temp != nullptr) temp->prev = tail;
        //         current->child = nullptr;
        //         current = temp;
        //     }
        // }
        return head;
    }
    
    Node* flattenandreturntail(Node *head) {
        Node* prev = nullptr;
        while (head != nullptr) {
            if(head->child == nullptr) {
                prev = head;
                head = head->next;
            } else {
                auto temp = head->next;
                auto child = head->child;
                head->next = child;
                child->prev = head;
                auto tail = flattenandreturntail(head->next);
                tail->next = temp;
                if (temp != nullptr) temp->prev = tail;
                head->child = nullptr;
                prev = tail;
                head = temp;
            }
        }
        return prev;
    }
};