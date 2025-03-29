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
        ListNode* start = new ListNode(-1);
        ListNode* answer = start;

        int sum = 0, carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10; 
            l1->val = sum;
            answer->next = l1;
            answer = answer->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2 == nullptr) {
            if (l1 == nullptr) {
                if (carry != 0) answer->next = new ListNode(carry);
            } else {
                while (l1 != nullptr) {
                    sum = l1->val + carry;
                    carry = sum/10;
                    sum = sum%10;
                    l1->val = sum;
                    answer->next = l1;
                    answer = answer->next;
                    l1 = l1->next;
                }
                if (carry != 0) {
                    answer->next = new ListNode(carry);
                }
            }
        }

        if (l1 == nullptr) {
            if (l2 == nullptr) {
                if (carry != 0) answer->next = new ListNode(carry);
            } else {
                while (l2 != nullptr) {
                    sum = l2->val + carry;
                    carry = sum/10;
                    sum = sum%10;
                    l2->val = sum;
                    answer->next = l2;
                    answer = answer->next;
                    l2 = l2->next;
                }
                if (carry != 0) {
                    answer->next = new ListNode(carry);
                }
            }
        }

        return start->next;
    }
};