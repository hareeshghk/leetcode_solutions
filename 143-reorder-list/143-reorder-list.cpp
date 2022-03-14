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
        ListNode *slow=head, *fast=head, *prev;
        do {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        } while(fast != nullptr && fast->next != nullptr);
        // cut the first part.
        // prev->next = nullptr;
        
        // reverse second half
        ListNode* secondhead = reverse(slow);
        
        // merge both
        ListNode *firsthead = head;
        
        while (firsthead != nullptr && secondhead != nullptr && firsthead != secondhead) {
            ListNode *temp = firsthead->next;
            firsthead->next = secondhead;
            ListNode *temp2 = secondhead->next;
            secondhead->next = temp;
            firsthead = temp;
            secondhead = temp2;   
        }
        firsthead->next = nullptr;
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