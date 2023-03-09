/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slowptr, fastptr;
        if (head == null) return null;
        slowptr = head;
        
        if (head.next == null) return null;
        
        fastptr = head.next;
        
        while (slowptr != null && fastptr != null && fastptr.next != null && slowptr != fastptr) {
            slowptr = slowptr.next;
            fastptr = fastptr.next.next;
        }
        
        if (fastptr== null || fastptr.next == null || slowptr ==null) return null;
        
        int count = 1;
        fastptr = fastptr.next;
        
        while (slowptr != fastptr) {
            ++count;
            fastptr = fastptr.next;
        }
        
        
        slowptr = head;
        fastptr = head;
        
        while (count-- > 0) {
            fastptr = fastptr.next;
        }
        
        while (slowptr != fastptr) {
            slowptr = slowptr.next;
            fastptr = fastptr.next;
        }
        
        return slowptr;
    }
}