#include <algorithm>
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        // cut at middle with slow fast pointers.
        ListNode *slow=head, *fast=head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse second half
        ListNode* secondhead = reverse(slow);
        
        // merge both
        ListNode *firsthead = head;
        
        while (secondhead->next != nullptr) {
            ListNode *temp = firsthead->next;
            firsthead->next = secondhead;
            ListNode *temp2 = secondhead->next;
            secondhead->next = temp;
            firsthead = temp;
            secondhead = temp2;   
        }
    }
    
    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode *prev=nullptr;
        while (head != nullptr) {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};
