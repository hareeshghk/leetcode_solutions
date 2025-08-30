#include <iostream>
#include <list>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        
        auto copyA = headA;
        auto copyB = headB;
        
        while (copyA != nullptr) {
            lenA++;
            copyA = copyA->next;
        }
        
        while (copyB != nullptr) {
            lenB++;
            copyB = copyB->next;
        }
        
        copyA = headA;
        copyB = headB;
        
        if (lenA > lenB) {
            for (int i = 0; i< lenA-lenB; ++i) {
                copyA = copyA->next;
            }
        } else {
            for (int i = 0; i<lenB-lenA; ++i) {
                copyB = copyB->next;
            }
        }
        
        while(copyA != nullptr && copyB != nullptr && copyA != copyB) {
            copyA = copyA->next;
            copyB = copyB->next;
        }
        return copyA;
    }
};
