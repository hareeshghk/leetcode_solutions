#include <iostream>
#include <list>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *endOfFirstPart, *startOfSecondPart;
    ListNode* partition(ListNode* head, int x) {
        startOfSecondPart = nullptr;
        endOfFirstPart = nullptr;
        
        return traverse(head, x);
    }
    
    ListNode* traverse(ListNode *head, int x) {
        if (head == nullptr) return nullptr;
        
        auto currentHead = traverse(head->next, x);
        
        if (head->val < x) {
            if (endOfFirstPart == nullptr) {
                endOfFirstPart = head;
            }
            head->next = currentHead;
            return head;
        } else {
            if (startOfSecondPart == nullptr) {
                startOfSecondPart = head;
                startOfSecondPart->next = nullptr;
                
                if (endOfFirstPart == nullptr) {
                    head->next = currentHead;
                    return head;
                } else {
                    endOfFirstPart->next = startOfSecondPart;
                    return currentHead;
                }
            } else {
                if (endOfFirstPart == nullptr) {
                    head->next = currentHead;
                    startOfSecondPart = head;
                    return head;
                } else {
                    head->next = startOfSecondPart;
                    startOfSecondPart = head;
                    endOfFirstPart->next = startOfSecondPart;
                    return currentHead;
                }
            }
        }
    }
};
