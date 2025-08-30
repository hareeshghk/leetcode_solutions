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
    ListNode* swapNodes(ListNode* head, int k) {
        int first = k;
        ListNode* firstPtr = nullptr;
        int list_len = 0;
        ListNode *start = head;
        while (start != nullptr) {
            if (list_len == first-1) firstPtr = start;
            start = start->next;
            list_len++;
        }
        
        int second = list_len - k + 1;
        if (first == second) return head;
        ListNode* secondPtr = nullptr;
        list_len = 0;
        start = head;
        while (start != nullptr) {
            if (list_len == second - 1) {
                secondPtr = start;
            }
            start = start->next;
            list_len++;
        }
        
        swap(firstPtr->val, secondPtr->val);
        return head;
    }
};
