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
    bool hasCycle(ListNode *head) {
        auto slowpointer = head;
        auto fastpointer = head;
        
        while (fastpointer != nullptr && fastpointer->next != nullptr) {
            slowpointer = slowpointer->next;
            fastpointer = fastpointer->next->next;
            if (fastpointer == slowpointer) return true;
        }
        return false;
    }
};
