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
        ListNode *slow, *fast;

        if (head == nullptr || head->next == nullptr) return false;

        slow = head->next;
        fast = head->next->next;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow == fast) return true;

        return false;
    }
};