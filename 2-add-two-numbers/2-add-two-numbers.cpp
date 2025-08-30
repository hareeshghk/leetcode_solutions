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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1, *prev = nullptr;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int x = l1->val + l2->val + carry;
            l1->val = x%10;
            carry = x/10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (l2 != nullptr) {
            if (prev == nullptr) {
                head = l2;
                l1 = l2;
            } else {
                prev->next = l2;
                l1 = prev->next;
            }
        }
        
        while (l1 != nullptr) {
            int x = l1->val+carry;
            l1->val = x%10;
            carry = x/10;
            prev = l1;
            l1 = l1->next;
        }
        
        if (carry != 0) {
            prev->next = new ListNode(carry);
        }
        
        return head;
    }
};
