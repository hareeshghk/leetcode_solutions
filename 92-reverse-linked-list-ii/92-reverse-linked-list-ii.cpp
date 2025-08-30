#include <algorithm>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev, *cur;
        
        cur = head;
        prev = nullptr;
        
        // get to left node
        for (int i = 0; i < left-1; ++i) {
            prev = cur;
            cur = cur->next;
        }
        
        
        // check cur being nullptr and raise left notfound exception
        
        ListNode *endOfFirstPart = prev;
        ListNode *endOfSecondPart = cur;
        
        // reverse until right position
        prev = nullptr;
        ListNode *temp;
        for (int i = left; i <=right; ++i) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        // stitch all parts.
        if (endOfFirstPart != nullptr) {
            endOfFirstPart->next = prev;
        } else {
            head = prev;
        }
        endOfSecondPart->next = cur;
        return head;
    }
};
