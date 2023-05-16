/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode answer = head.next;
        
        ListNode previous = null;
        ListNode current = head;
        
        while (current != null && current.next != null) {
            ListNode temp = current.next.next;
            current.next.next = current;
            if (previous != null) {
                previous.next = current.next;
            }
            current.next = temp;
            previous = current;
            current = temp;
        }
        
        if (previous != null) {
            previous.next = current;
        }
        
        return answer;
    }
}