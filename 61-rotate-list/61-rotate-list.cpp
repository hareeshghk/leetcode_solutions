#include <iostream>
#include <list>

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        
        int listsize = 1;
        ListNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
            ++listsize;
        }
        
        k = k%listsize;
        
        // no rotation needed.
        if (k==0) return head;
        
        //join ends
        current->next = head;
        
        // move first k elements to back;
        k = listsize-k;
        
        
        for (int i = 0; i < k; i++) {
            current = head;
            head = head->next;
        }
        
        current->next = nullptr;
        return head;
    }
};
